#pragma once
#include "afxcmn.h"


// CDiaXianCheng �Ի���

class CDiaXianCheng : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaXianCheng)

public:
	CDiaXianCheng(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDiaXianCheng();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGXianCheng };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ListCtrl;
	BOOL OnInitDialog();
	BOOL BianLi();
	afx_msg void OnBnClickedkill();
	CString temp2;
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedGuaqi();
	afx_msg void OnBnClickedButton2();
};
