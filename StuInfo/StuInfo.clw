; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CStudentDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "stuinfo.h"
LastPage=0

ClassCount=10
Class1=CCourseSet
Class2=CScoreSet
Class3=CStudentSet
Class4=CStuInfoApp
Class5=CAboutDlg
Class6=CStuInfoDlg

ResourceCount=6
Resource1=IDD_STUINFO_DIALOG
Resource2=IDD_ABOUTBOX
Class7=CStudentDlg
Resource3=IDD_SCORE
Class8=CCourseDlg
Resource4=IDD_COURSE
Class9=CScoreDlg
Resource5=IDD_STUDENT
Class10=CAvgScoreDlg
Resource6=IDD_AVGSCORE

[CLS:CCourseSet]
Type=0
HeaderFile=CourseSet.h
ImplementationFile=CourseSet.cpp
LastObject=CCourseSet

[CLS:CScoreSet]
Type=0
HeaderFile=ScoreSet.h
ImplementationFile=ScoreSet.cpp
Filter=N
BaseClass=CRecordset
VirtualFilter=r

[CLS:CStudentSet]
Type=0
HeaderFile=StudentSet.h
ImplementationFile=StudentSet.cpp
LastObject=CStudentSet

[CLS:CStuInfoApp]
Type=0
BaseClass=CWinApp
HeaderFile=StuInfo.h
ImplementationFile=StuInfo.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=StuInfoDlg.cpp
ImplementationFile=StuInfoDlg.cpp
LastObject=CAboutDlg

[CLS:CStuInfoDlg]
Type=0
BaseClass=CDialog
HeaderFile=StuInfoDlg.h
ImplementationFile=StuInfoDlg.cpp
LastObject=IDC_CHOOSE
Filter=D
VirtualFilter=dWC

[DB:CCourseSet]
DB=1

[DB:CScoreSet]
DB=1
DBType=ODBC
ColumnCount=4
Column1=[studentno], 12, 16
Column2=[courseno], 12, 14
Column3=[score], 7, 4
Column4=[credit], 7, 4

[DB:CStudentSet]
DB=1

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_STUINFO_DIALOG]
Type=1
Class=CStuInfoDlg
ControlCount=12
Control1=IDC_LIST,SysListView32,1350631425
Control2=IDC_SEARCH,button,1342242816
Control3=IDC_ADD,button,1342242816
Control4=IDC_MODIFY,button,1342242816
Control5=IDC_DELETE,button,1342242816
Control6=IDC_STATIC,button,1342178055
Control7=IDC_CHOOSE,combobox,1344339971
Control8=IDC_SUMCREDIT,button,1342242816
Control9=IDC_STUDENTST,button,1342242816
Control10=IDC_AVGSCORE,button,1342242816
Control11=IDC_COURSEST,button,1342242816
Control12=IDC_STATIC,button,1342178055

[DLG:IDD_STUDENT]
Type=1
Class=CStudentDlg
ControlCount=14
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STUDENTNAME,edit,1350631552
Control10=IDC_STUDENTNO,edit,1350631552
Control11=IDC_XB,edit,1350631552
Control12=IDC_BIRTHDAY,edit,1350631552
Control13=IDC_SPECIAL,edit,1350631552
Control14=IDC_TOTALCREDIT,edit,1350631552

[CLS:CStudentDlg]
Type=0
HeaderFile=StudentDlg.h
ImplementationFile=StudentDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CStudentDlg

[DLG:IDD_COURSE]
Type=1
Class=CCourseDlg
ControlCount=16
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_COURSENO,edit,1350631552
Control11=IDC_SPECIAL2,edit,1350631552
Control12=IDC_COURSENAME,edit,1350631552
Control13=IDC_COURSETYPE,edit,1350631552
Control14=IDC_OPENTERM,edit,1350631552
Control15=IDC_HOURS,edit,1350631552
Control16=IDC_CREDIT,edit,1350631552

[CLS:CCourseDlg]
Type=0
HeaderFile=CourseDlg.h
ImplementationFile=CourseDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CCourseDlg

[DLG:IDD_SCORE]
Type=1
Class=CScoreDlg
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STUDENTNO2,edit,1350631552
Control8=IDC_COURSENO2,edit,1350631552
Control9=IDC_GRADE,edit,1350631552
Control10=IDC_CREDIT2,edit,1350631552

[CLS:CScoreDlg]
Type=0
HeaderFile=ScoreDlg.h
ImplementationFile=ScoreDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CScoreDlg

[DLG:IDD_AVGSCORE]
Type=1
Class=CAvgScoreDlg
ControlCount=9
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_CHOOSEXB,combobox,1344340227
Control5=IDC_CHOOSECOURSE,combobox,1344340227
Control6=IDC_CHOOSENO,combobox,1344340227
Control7=IDC_AVGBYXB,edit,1350631552
Control8=IDC_AVGBYCOURSE,edit,1350631552
Control9=IDC_AVGBYNO,edit,1350631552

[CLS:CAvgScoreDlg]
Type=0
HeaderFile=AvgScoreDlg.h
ImplementationFile=AvgScoreDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CAvgScoreDlg

