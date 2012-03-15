// TeachingDialog.cpp : implementation file
//

#include "stdafx.h"
#include "iMobotController_Windows.h"
#include "TeachingDialog.h"


// CTeachingDialog dialog

IMPLEMENT_DYNAMIC(CTeachingDialog, CDialog)

CTeachingDialog::CTeachingDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CTeachingDialog::IDD, pParent)
{
  /* Read the config file */
  if(SHGetFolderPathA(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, _path) != S_OK) 
  {
    /* Could not get the user's app data directory */
  } else {
    //MessageBox((LPCTSTR)path, (LPCTSTR)"Test");
    //fprintf(fp, "%s", path); 
  }
  strcat(_path, "\\Barobo.config");
  _robotManager.read(_path);

}

CTeachingDialog::~CTeachingDialog()
{
}

void CTeachingDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTeachingDialog, CDialog)
END_MESSAGE_MAP()


// CTeachingDialog message handlers