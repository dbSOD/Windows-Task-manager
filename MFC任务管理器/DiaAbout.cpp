// DiaAbout.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC���������.h"
#include "DiaAbout.h"
#include "afxdialogex.h"


// CDiaAbout �Ի���

IMPLEMENT_DYNAMIC(CDiaAbout, CDialogEx)

CDiaAbout::CDiaAbout(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ABOUTBOX, pParent)
{

}

CDiaAbout::~CDiaAbout()
{
}

BOOL CDiaAbout::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	HMENU m_hMenu1 = NULL;
	::SetMenu(this->GetSafeHwnd(), m_hMenu1);
	return true;

}

void CDiaAbout::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDiaAbout, CDialogEx)
END_MESSAGE_MAP()


// CDiaAbout ��Ϣ�������
