#pragma once


// CDigInformation �Ի���

class CDigInformation : public CDialogEx
{
	DECLARE_DYNAMIC(CDigInformation)

public:
	CDigInformation(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDigInformation();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGInformation };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
