#pragma once
#include "afxcmn.h"

// CDiaJincheng �Ի���

class CDiaJincheng : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaJincheng)

public:
	CDiaJincheng(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDiaJincheng();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGJincheng };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ListCtrl;
	BOOL OnInitDialog();
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	void BianLi();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedmokuai();
	CString temp2;
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickeddui();
};
