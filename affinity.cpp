#include "affinity.h"
#include <stdio.h>
#include <unistd.h>

#include <thread>
#include <QMessageBox>

AffinityTest::AffinityTest( QWidget* parent) : QWidget( parent)
{
	ui.setupUi(this);
	startTimer(200);
	memset(&m_ThreadData, 0, sizeof(m_ThreadData));
}

AffinityTest::~AffinityTest()
{
}

void AffinityTest::on_checkBoxThread1Core1_clicked(bool value) { onCheckBox(1, 1, value); }
void AffinityTest::on_checkBoxThread1Core2_clicked(bool value) { onCheckBox(1, 2, value); }
void AffinityTest::on_checkBoxThread1Core3_clicked(bool value) { onCheckBox(1, 3, value); }
void AffinityTest::on_checkBoxThread1Core4_clicked(bool value) { onCheckBox(1, 4, value); }
void AffinityTest::on_checkBoxThread2Core1_clicked(bool value) { onCheckBox(2, 1, value); }
void AffinityTest::on_checkBoxThread2Core2_clicked(bool value) { onCheckBox(2, 2, value); }
void AffinityTest::on_checkBoxThread2Core3_clicked(bool value) { onCheckBox(2, 3, value); }
void AffinityTest::on_checkBoxThread2Core4_clicked(bool value) { onCheckBox(2, 4, value); }
void AffinityTest::on_checkBoxThread3Core1_clicked(bool value) { onCheckBox(3, 1, value); }
void AffinityTest::on_checkBoxThread3Core2_clicked(bool value) { onCheckBox(3, 2, value); }
void AffinityTest::on_checkBoxThread3Core3_clicked(bool value) { onCheckBox(3, 3, value); }
void AffinityTest::on_checkBoxThread3Core4_clicked(bool value) { onCheckBox(3, 4, value); }

void AffinityTest::on_pushButtonStart1_clicked(bool) { onStartThread(1); }
void AffinityTest::on_pushButtonStart2_clicked(bool) { onStartThread(2); }
void AffinityTest::on_pushButtonStart3_clicked(bool) { onStartThread(3); }

void AffinityTest::onCheckBox(int thread_num, int core_num, bool value)
{
	if(value)
		m_ThreadData[thread_num-1].core_mask |= (1<<(core_num-1));
	else
		m_ThreadData[thread_num-1].core_mask &= ~(1<<(core_num-1));

//    m_ThreadData[thread_num-1].core_changed = 1;
    if(m_ThreadData[thread_num-1].thread_started)
    {
//        HANDLE abs_handle = OpenThread(THREAD_ALL_ACCESS, false, (DWORD) m_ThreadData[thread_num-1].thread_handle);
//        int res = SetThreadAffinityMask(abs_handle, m_ThreadData[thread_num-1].core_mask);
//        qDebug("handle=%d oldmask=%d newmask=%d", abs_handle, res, m_ThreadData[thread_num-1].core_mask);


        int res = SetThreadAffinityMask(m_ThreadData[thread_num-1].thread_handle, m_ThreadData[thread_num-1].core_mask);
        qDebug("handle=%d oldmask=%d newmask=%d", m_ThreadData[thread_num-1].thread_handle, res, m_ThreadData[thread_num-1].core_mask);
    }
}

DWORD WINAPI DumbThreadFunction2(void *pData);

void AffinityTest::onStartThread(int ThreadNum)
{
	QLineEdit *qle[] = {ui.lineEditResultThread1, ui.lineEditResultThread2, ui.lineEditResultThread3};

	if(m_ThreadData[ThreadNum-1].core_mask==0)
	{
		QMessageBox::critical(this, "Error", "No cores specified for thread");
		return;
	}

	m_ThreadData[ThreadNum-1].thread_index = ThreadNum-1;
	m_ThreadData[ThreadNum-1].core_changed = 1;

//	qle[ThreadNum-1]->setText("started");
    std::thread *t = new std::thread(&AffinityTest::DumbThreadFunction1, this, &m_ThreadData[ThreadNum-1]);

     //  m_ThreadData[ThreadNum-1].thread_handle = (HANDLE)t->native_handle();
     //qDebug("Thread started Handle=%d", m_ThreadData[ThreadNum-1].thread_handle);


//    DWORD threadID;
//    HANDLE threadHandle = CreateThread(NULL, 0, DumbThreadFunction2, (void*)&m_ThreadData[ThreadNum-1], 0, &threadID);
//    m_ThreadData[ThreadNum-1].thread_handle = threadHandle;
//    qDebug("Thread started Handle=%d ID=%d", threadHandle, threadID);
}


void AffinityTest::DumbThreadFunction1(thread_data *pData)
//DWORD WINAPI DumbThreadFunction2(void *pData2)
{
//       thread_data *pData = (thread_data*)pData2;
#ifndef WIN32
	cpu_set_t cpuset;
	pthread_t thread;
	thread = pthread_self();
    CPU_ZERO(&cpuset);
#else
    HANDLE thread = GetCurrentThread();
#endif

    int j;

#ifndef WIN32
    for (j = 0; j < 4; j++)
		if(pData->core_mask & (1<<j))
			CPU_SET(j, &cpuset);
    pthread_setaffinity_np(thread, sizeof(cpu_set_t), &cpuset);
#else
    int res = SetThreadAffinityMask(thread, pData->core_mask);
    qDebug("starthandle=%d oldmask=%d, newmask=%d", thread, res, pData->core_mask);
#endif


	pData->core_changed = 0;


//    pData->thread_handle = (THREADHANDLE)GetCurrentThreadId();
    pData->thread_handle = OpenThread(THREAD_ALL_ACCESS, false, GetCurrentThreadId());


	pData->thread_started = 1;

	time_t tstart, tend;
	tstart = time(NULL);

	double Sum = 0;
    for(long long i=0; i<1000000000; i++)
	{
        if((i%10000000) == 0)
		{
            if((i%100000000) == 0)
			{
				//printf("X%d\n", pData->thread_index);
                long long temp = (i*100)/1000000000;
                pData->status = temp;
				pData->status_changed = 1;
			}

/*			if(pData->core_changed)
			{
#ifndef WIN32
				CPU_ZERO(&cpuset);
				for (j = 0; j < 4; j++)
					if(pData->core_mask & (1<<j))
						CPU_SET(j, &cpuset);
				pthread_setaffinity_np(thread, sizeof(cpu_set_t), &cpuset);
#else
                int res = SetThreadAffinityMask(thread, pData->core_mask);
                qDebug("oldmask=%d newmask=%d", res, pData->core_mask);
#endif

				pData->core_changed = 0;
			}
*/
            usleep(10000);
		}
        Sum += 1./(i+time(NULL));
	}

    tend = time(NULL);


	qDebug("ended ");
	pData->status_changed = 1;
	pData->status = 100;
    pData->global_time = tend-tstart;
//	qle[pData->thread_index]->setText("ended " + QString("(%1)").arg(tend-tstart));	//DANGEROUS?
	pData->thread_started = 0;

#ifdef WIN32
    CloseHandle(pData->thread_handle);
#endif
}


void AffinityTest::timerEvent(QTimerEvent *event)
{
	QLineEdit *qle[] = {ui.lineEditResultThread1, ui.lineEditResultThread2, ui.lineEditResultThread3};

	for(int i=0; i<3; i++)
		if(m_ThreadData[i].status_changed)
		{
			if(m_ThreadData[i].status>=100)
				qle[m_ThreadData[i].thread_index]->setText("ended " + QString("(%1)").arg(m_ThreadData[i].global_time));	
			else	
				qle[m_ThreadData[i].thread_index]->setText(QString("%1 %").arg(m_ThreadData[i].status));	
			m_ThreadData[i].status_changed = 0;
		}
}
