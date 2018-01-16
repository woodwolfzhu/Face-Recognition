// 人脸检测与识别系统.h : main header file for the 人脸检测与识别系统 application
//

#if !defined(AFX_FACEDETECT_H__886D028A_D9CC_4C74_BC90_F3DE1357CED5__INCLUDED_)
#define AFX_FACEDETECT_H__886D028A_D9CC_4C74_BC90_F3DE1357CED5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// C人脸检测与识别系统App:
// See 人脸检测与识别系统.cpp for the implementation of this class
//

class C人脸检测与识别系统App : public CWinApp
{
public:
	C人脸检测与识别系统App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(C人脸检测与识别系统App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(C人脸检测与识别系统App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FACEDETECT_H__886D028A_D9CC_4C74_BC90_F3DE1357CED5__INCLUDED_)
