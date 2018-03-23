// DiaMokuai.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC���������.h"
#include "DiaMokuai.h"
#include "afxdialogex.h"
#include <TlHelp32.h>
#include <wchar.h>

// CDiaMokuai �Ի���

IMPLEMENT_DYNAMIC(CDiaMokuai, CDialogEx)

CDiaMokuai::CDiaMokuai(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOGMokuai, pParent)
{

}

CDiaMokuai::~CDiaMokuai()
{
}

void CDiaMokuai::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_LIST1, m_ListCtrl2);
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl2);
}

BOOL CDiaMokuai::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	DWORD dwOldStyle = m_ListCtrl2.GetExtendedStyle();
	m_ListCtrl2.SetExtendedStyle(
		dwOldStyle | LVS_EX_FULLROWSELECT |
		LVS_EX_GRIDLINES |
		LVS_EX_CHECKBOXES
	);
	CRect rc;
	m_ListCtrl2.GetClientRect(rc);
	int nWidth = rc.Width();
	m_ListCtrl2.InsertColumn(0, L"ģ����", 0, nWidth / 4);
	m_ListCtrl2.InsertColumn(1, L"ģ���������̵�id", 0, nWidth / 4);
	m_ListCtrl2.InsertColumn(2, L"ģ��·��", 0, nWidth / 4);
	m_ListCtrl2.InsertColumn(3, L"ģ���ڴ��С", 0, nWidth / 4);


	WORD n;
	n = _wtoi(pocessID);
	HANDLE hTool32 = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, n);
	if (INVALID_HANDLE_VALUE == hTool32)
	{
		MessageBoxW(L"����error!");
		//	printf("����error!\n");
		return FALSE;
	}
	// 2. ��ʼ��������
	MODULEENTRY32 ti = { sizeof(MODULEENTRY32) };
	BOOL bRet = Module32First(hTool32, &ti);
	m_ListCtrl2.InsertItem(0, ti.szModule);
	if (!bRet)
	{
		printf("Thread32First error!\n");
		return false;
	}
	int i = 0;
	do
	{
		//if (ti.th32OwnerProcessID == dwPID)
		{
			m_ListCtrl2.UpdateWindow();
			m_ListCtrl2.InsertItem(i, ti.szModule);
			CString str;
			str.Format(_T("%ld"), ti.th32ProcessID);
			m_ListCtrl2.SetItemText(i, 1, str);
			m_ListCtrl2.SetItemText(i, 2, ti.szExePath);
			str.Format(_T("%ld"), ti.modBaseSize);
			m_ListCtrl2.SetItemText(i, 3, str);
			i++;
		}
	} while (Module32Next(hTool32, &ti));





	return true;
}


BEGIN_MESSAGE_MAP(CDiaMokuai, CDialogEx)
END_MESSAGE_MAP()


// CDiaMokuai ��Ϣ�������
