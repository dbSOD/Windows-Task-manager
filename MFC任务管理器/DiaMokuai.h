#pragma once
#include "afxcmn.h"


// CDiaMokuai �Ի���

class CDiaMokuai : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaMokuai)

public:
	CDiaMokuai(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDiaMokuai();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGMokuai };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
//	CListCtrl m_ListCtrl2;
	CString pocessID;
	BOOL OnInitDialog();
	CListCtrl m_ListCtrl2;
};
