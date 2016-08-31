#ifndef _AFFINITY_H
#define _AFFINITY_H

#include "ui_affinityform.h"

#define WIN32

#include <windows.h>

typedef HANDLE THREADHANDLE;

struct thread_data {
	int thread_index;
	int core_mask;
	int core_changed;
	int thread_started;
	int status;
	int status_changed;
	int global_time;
    THREADHANDLE thread_handle;
};

class AffinityTest : public QWidget
{
    Q_OBJECT

public:
    AffinityTest( QWidget* parent = 0);
    ~AffinityTest();

private:
    	Ui::AffinityForm ui;	
	void DumbThreadFunction1(thread_data*);
	thread_data m_ThreadData[3];

	void onCheckBox(int thread_num, int core_num, bool);
	void onStartThread(int ThreadNum);
	void timerEvent(QTimerEvent *event);


public slots:
	void on_pushButtonStart1_clicked(bool);
	void on_pushButtonStart2_clicked(bool);
	void on_pushButtonStart3_clicked(bool);

	void on_checkBoxThread1Core1_clicked(bool);
	void on_checkBoxThread1Core2_clicked(bool);
	void on_checkBoxThread1Core3_clicked(bool);
	void on_checkBoxThread1Core4_clicked(bool);

	void on_checkBoxThread2Core1_clicked(bool);
	void on_checkBoxThread2Core2_clicked(bool);
	void on_checkBoxThread2Core3_clicked(bool);
	void on_checkBoxThread2Core4_clicked(bool);

	void on_checkBoxThread3Core1_clicked(bool);
	void on_checkBoxThread3Core2_clicked(bool);
	void on_checkBoxThread3Core3_clicked(bool);
	void on_checkBoxThread3Core4_clicked(bool);
};

#endif
