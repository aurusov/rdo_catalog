#ifndef RDOTABCTRL_H
#define RDOTABCTRL_H
#pragma once

#include <afxcmn.h>
#include <afxwin.h>

// ----------------------------------------------------------------------------
// ---------- RDOTabCtrl
// ----------------------------------------------------------------------------
class RDOTab;

class RDOTabCtrl: public CWnd
{
protected:
	RDOTab* tab;
	bool autoDelete;

	//{{AFX_MSG(RDOTabCtrl)
	afx_msg int OnCreate( LPCREATESTRUCT lpCreateStruct );
	afx_msg void OnDestroy();
	afx_msg void OnShowWindow( BOOL bShow, UINT nStatus );
	afx_msg void OnSetFocus( CWnd *pOldWnd );
	afx_msg void OnSize( UINT nType, int cx, int cy );
	afx_msg void OnEnable( BOOL bEnable );
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_VIRTUAL(RDOTabCtrl)
	public:
	virtual BOOL OnCmdMsg( UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo );
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

public:
	RDOTabCtrl();
	virtual ~RDOTabCtrl();

	int   getItemCount() const;
	CWnd* getItem( const int index ) const;
	CWnd* getItemNext( const CWnd* const currentItem = NULL, const bool direction = true, const bool loop = true ) const;
	CWnd* getItemCurrent() const;
	int   getCurrentIndex() const;
	int   findItem( const CWnd* const item ) const;
	void  insertItem( CWnd* pWnd, LPCTSTR lpName );
	void  setCurrentItem( const int index );

	virtual void changeCurrentItem();

	void setAutoDelete( const bool value ) { autoDelete = value; };

	void modifyTabStyle( DWORD dwRemove, DWORD dwAdd, UINT nFlags = 0 );
};

#endif // RDOTABCTRL_H
