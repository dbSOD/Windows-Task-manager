#pragma once
#include "afxcmn.h"


// CDiaDui �Ի���

class CDiaDui : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaDui)

public:
	CDiaDui(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDiaDui();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGDui };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ListCtrl2;
	CString pocessID;
	BOOL OnInitDialog();
};
