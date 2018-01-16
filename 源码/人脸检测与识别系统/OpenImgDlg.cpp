// OpenImgDlg.cpp : implementation file
//

#include "stdafx.h"
#include "OpenImgDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COpenImgDlg

IMPLEMENT_DYNAMIC(COpenImgDlg, CFileDialog)

COpenImgDlg::COpenImgDlg(BOOL bOpenFileDialog, LPCTSTR lpszDefExt, LPCTSTR lpszFileName,
		DWORD dwFlags, LPCTSTR lpszFilter, CWnd* pParentWnd) :
		CFileDialog(bOpenFileDialog, lpszDefExt, lpszFileName, dwFlags, lpszFilter, pParentWnd)
{
	m_pszFile = new TCHAR[2048]; //set a 2K buffer to hold selected files
	m_pszFile[0] = '\0'; //initialize pointer;
}

COpenImgDlg::~COpenImgDlg()
{
	if (m_pszFile != NULL)
		delete [] m_pszFile; //cleanup
}
int COpenImgDlg::DoModal()
{
	ASSERT_VALID(this);
	ASSERT(m_ofn.Flags & OFN_ALLOWMULTISELECT); //make sure multiple file selection is on

	m_ofn.lpstrFile = m_pszFile; //initialize the OPENFILENAME structure
	m_ofn.nMaxFile = 2048;

	return CFileDialog::DoModal();
}


BEGIN_MESSAGE_MAP(COpenImgDlg, CFileDialog)
	//{{AFX_MSG_MAP(COpenImgDlg)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

