
// MFC���������Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxshelltreectrl.h"
#include "afxshelllistctrl.h"
#include "MyTableCtrl.h"
#define WM_GETMOKUAI WM_USER +1 
#define WM_GETDUI WM_USER +2 

// CMFC���������Dlg �Ի���
class CMFC���������Dlg : public CDialogEx
{
// ����
public:
	CMFC���������Dlg(CWnd* pParent = NULL);	// ��׼���캯��
	CMenu m_Menu;
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CMFCShellTreeCtrl m_SheelTree;
	CMFCShellListCtrl m_ShellList;
	CString m_foldload;
	afx_msg void OnNMClickMfcshelltree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMDblclkMfcshelltree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTvnSelchangingMfcshelltree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedClean();
	void EnumLoad(TCHAR* load);
	void deleteFolder(TCHAR* load);
	afx_msg void OnBnClickedHuoquWenjian();
	CString wenJianMing;//�ļ���
	afx_msg void OnNMClickMfcshelllist1(NMHDR *pNMHDR, LRESULT *pResult);
	CString m_wenJianXinXi;
	CMyTableCtrl m_MyTable;
protected:
	afx_msg LRESULT OnGetmokuai(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnGetdui(WPARAM wParam, LPARAM lParam);
};
