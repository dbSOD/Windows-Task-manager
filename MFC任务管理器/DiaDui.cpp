// DiaDui.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC���������.h"
#include "DiaDui.h"
#include "afxdialogex.h"
#include <TlHelp32.h>
#include <wchar.h>

// CDiaDui �Ի���

IMPLEMENT_DYNAMIC(CDiaDui, CDialogEx)

CDiaDui::CDiaDui(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOGDui, pParent)
{

}

CDiaDui::~CDiaDui()
{
}

void CDiaDui::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl2);
}

BOOL CDiaDui::OnInitDialog()
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
	m_ListCtrl2.InsertColumn(0, L"�ѱ�ʶ��", 0, nWidth / 2);
	m_ListCtrl2.InsertColumn(1, L"���̱�ʶ��id", 0, nWidth / 2);
	WORD n;
	n = _wtoi(pocessID);
	HANDLE hTool32 = CreateToolhelp32Snapshot(TH32CS_SNAPHEAPLIST, n);
	if (INVALID_HANDLE_VALUE == hTool32)
	{
		MessageBoxW(L"����error!");
		//	printf("����error!\n");
		return FALSE;
	}
	// 2. ��ʼ��������
	HEAPLIST32 ti = { sizeof(HEAPLIST32) };
	BOOL bRet = Heap32ListFirst(hTool32, &ti);
	CString str;
	str.Format(_T("%ld"), ti.th32HeapID);
	m_ListCtrl2.InsertItem(0, str);
	if (!bRet)
	{
		printf("Heap32ListFirst error!\n");
		return false;
	}
	int i = 0;
	do
	{
		//if (ti.th32OwnerProcessID == dwPID)
		{
			m_ListCtrl2.UpdateWindow();
			str.Format(_T("%ld"), ti.th32ProcessID);
			m_ListCtrl2.SetItemText(i, 1, str);
			i++;
		}
	} while (Heap32ListNext(hTool32, &ti));





	return true;
}


BEGIN_MESSAGE_MAP(CDiaDui, CDialogEx)
END_MESSAGE_MAP()


// CDiaDui ��Ϣ�������
