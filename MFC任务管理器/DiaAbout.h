#pragma once


// CDiaAbout �Ի���

class CDiaAbout : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaAbout)

public:
	CDiaAbout(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDiaAbout();
	BOOL OnInitDialog();
	
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
