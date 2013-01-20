#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QTextEdit>
#include <QAction>
#include <QMenu>
#include <QListWidget>
#include <QSplitter>

#include "page.h"
#include "highlighter.h"
#include "holwidget.h"
#include "holmakewidget.h"
#include "project.h"
#include "projectview.h"
#include "transistiondiagramwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private slots:
    void newBlankPage();
    Page* addPage(const QString &name);
    void openPage();
    void saveTab();
    void savePageAs();
    void close();

    void undo();
    void redo();
    void cut();
    void copy();
    void paste();
    void selectAll();
    void findReplace();

    void closeTab(int index);

    void fileViewItemSelected( const QModelIndex & current, const QModelIndex & previous);

    /* HOL Slots */
    //void sendRegionToHOL();
    void runHolmake();

    /* Project Slots */
    void newProject();
    void openProject();
    void saveProject();
    void saveProjectAs();

    void showTransistionDiagram();
    void showProjectView();

protected:

    int mNewFileCounter;

private:  
    void createStatusBar();
    void createActions();
    void createMenus();
    void createToolBars();
    void createDockWindows();

    void setStatus(const QString &message);

    void save(Page* page);
    void open(const QString &name);

    void saveProjectFile();
    //void open(ProjectView* projectView);

    /* Main Interface */
    QTabWidget* mTabWidget;
    QTextEdit* mIntroPage;

    /* Actions */
    // File Menu
    QAction* mNewFileAction;
    QAction* mOpenFileAction;
    QAction* mSaveFileAction;
    QAction* mSaveAsFileAction;
    QAction* mExitAction;

    /* Project */
    QAction* mNewProjectAction;
    QAction* mOpenProjectAction;
    QAction* mSaveProjectAction;
    QAction* mSaveProjectAsAction;
    QAction* mShowProjectViewAction;
    QAction* mShowTransistionDiagramAction;
    QAction* mGenerateHOLAction;
    QAction* mGenerateHaskellAction;
    QAction* mGenerateDocAction;
    QAction* mCloseProjectAction;

    // Edit Menu
    QAction* mUndoAction;
    QAction* mRedoAction;
    QAction* mCutAction;
    QAction* mCopyAction;
    QAction* mPasteAction;
    QAction* mSelectAllAction;
    QAction* mFindReplaceAction;

    //HOL Menu
    QAction* mHOLRestartAction;
    QAction* mHOLSendRegionToAction;
    QAction *mHOLRunHolmakeAction;

    /*
    QAction *mHOLNewGoalAction;
    QAction *mHOLApplyTacticAction;
    QAction *mHOLBackupAction;
    QAction *mHOLSaveAction;
    QAction *mHOLRestoreAction;
    QAction *mHOLRotateAction;
    QAction *mHOLSubgoalTacticAction;
    QAction *mHOLNameTopTheoremAction;
    */

    QAction *mHOLShowTypesAction;
    QAction *mHOLShowTypesVerboseAction;
    QAction *mHOLShowNumericalTypesAction;
    QAction *mHOLShowAssumptionsAction;

    // Help
    QAction* mHOLDocumentationAction;
    QAction* mAboutAction;

    // Transistion Diagram
    QAction* mAddStateAction;
    QAction* mDeleteStateAction;
    QAction* mMakeLinkAction;
    QAction* mDeleteLinkAction;
    QAction* mStatePropertiesAction;
    QAction* mZoomInAction;
    QAction* mZoomOutAction;

    /* Menu */
    QMenu* mFileMenu;
    QMenu* mProjectMenu;
    QMenu* mEditMenu;
    QMenu* mHOLMenu;
    QMenu* mHOLProcessMenu;
    QMenu* mHOLGoalMenu;
    QMenu* mHOLPrintMenu;
    QMenu* mHaskellMenu;
    QMenu *mHelpMenu;

    /* Tool bars */
    QToolBar *mTransistionDiagramToolbar;

    /* Highlighter*/
    Highlighter *highlighter;

    /* Dockables */
    HOLWidget* mHOLWidget;
    QSplitter* mFileViewSplitter;

    HOLMakeWidget* mHolmakeWidget;

    /* Project */
    Project *mProject;
    ProjectView *mProjectView;
    TransistionDiagramWidget *mTransistionDiagram;
};

#endif // MAINWINDOW_H
