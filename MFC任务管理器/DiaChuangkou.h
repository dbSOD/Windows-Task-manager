#pragma once
#include "afxcmn.h"


// CDiaChuangkou �Ի���

class CDiaChuangkou : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaChuangkou)

public:
	CDiaChuangkou(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDiaChuangkou();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGChuangkou };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ListCtrl;
	static int m;
	afx_msg void OnBnClickedOk();
};
