#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtGui>
#include <QString>
#include <QItemSelectionModel>

#include "mainwindow.h"
#include "page.h"
#include "holwidget.h"
#include "holmakewidget.h"
#include "project.h"
#include "projectview.h"
#include "transistiondiagramwidget.h"

MainWindow::MainWindow() {
    mNewFileCounter = 1;
    mProject = 0;
    mTransistionDiagram = 0;
    mProjectView = 0;

    mTabWidget = new QTabWidget;
    mTabWidget->setTabsClosable(true);
    connect(mTabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab(int)));
    setCentralWidget(mTabWidget);

    createStatusBar();
    createDockWindows();
    createActions();
    createMenus();
    createToolBars();

    newBlankPage();
}

void MainWindow::newBlankPage() {
   addPage("New " + QString::number(mNewFileCounter++));
}

Page* MainWindow::addPage(const QString &path) {
   Page* newPage = new Page;
   newPage->setFilePath(path);

   QFileInfo pathInfo( path );
   QString fileName = pathInfo.fileName();
   newPage->setFileName(fileName);

   highlighter = new Highlighter(newPage->document());

   int index = mTabWidget->addTab(newPage, fileName);
   mTabWidget->setCurrentIndex(index);
   return newPage;
}

void MainWindow::openPage() {
    QString fileName = QFileDialog::getOpenFileName(this);
    if (fileName.isEmpty()) {
        return;
    }

    open(fileName);
}

void MainWindow::saveTab() {
    qDebug() << "\n[*] MainWindow::saveTab";

    /* Determine page type */
    ProjectView *projectView = qobject_cast<ProjectView*>(mTabWidget->currentWidget());
    TransistionDiagramWidget *diagramWidget = qobject_cast<TransistionDiagramWidget*>(mTabWidget->currentWidget());

    if (projectView) {
        qDebug() << "[+] Saving Project View";
        saveProjectFile();
        return;
    } else if (diagramWidget) {
        qDebug() << "[+] Saving Diagram Window";
        mTransistionDiagram->saveStates();
        return;
    }

    qDebug() << "[+] Saving Page";

    Page *page = qobject_cast<Page*>(mTabWidget->currentWidget());

    //if (page->document()->isModified()) {
    //    QMessageBox::StandardButton ret;
    //    ret = QMessageBox::warning(this, tr("HOLIDE"), tr("The document has been modified.\n"
    //                                                     "Do you want to save your changes?"),
    //                               QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    //    if (ret == QMessageBox::Save)
    return save(page);
    //}
}

void MainWindow::savePageAs() {
    QString filePath = QFileDialog::getSaveFileName(this);
    if (filePath.isEmpty()) {
        return;
    }

    int currentTab = mTabWidget->currentIndex();
    Page* page = (Page*)mTabWidget->widget(currentTab);
    page->setFilePath(filePath);

    QFileInfo pathInfo(filePath);
    QString fileName = pathInfo.fileName();
    page->setFileName(fileName);

    mTabWidget->setTabText(currentTab, fileName);

    save(page);
}

void MainWindow::close() {}

void MainWindow::closeTab(int index) {
    mTabWidget->removeTab(index);
}

void MainWindow::createStatusBar() {
   statusBar()->showMessage(tr("Ready"));
}

void MainWindow::createActions() {
    mNewFileAction = new QAction(QIcon(":/images/new.png"), tr("&New"), this);
    mNewFileAction->setShortcut(QKeySequence::New);
    mNewFileAction->setStatusTip(tr("Open a new file"));
    connect(mNewFileAction, SIGNAL(triggered()), this, SLOT(newBlankPage()));

    mOpenFileAction = new QAction(QIcon(":/images/open.png"), tr("&Open"), this);
    mOpenFileAction->setShortcut(QKeySequence::Open);
    mOpenFileAction->setStatusTip(tr("Open file"));
    connect(mOpenFileAction, SIGNAL(triggered()), this, SLOT(openPage()));

    mSaveFileAction = new QAction(QIcon(":/images/save.png"), tr("&Save"), this);
    mSaveFileAction->setShortcut(QKeySequence::Save);
    mSaveFileAction->setStatusTip(tr("Save file"));
    connect(mSaveFileAction, SIGNAL(triggered()), this, SLOT(saveTab()));

    mSaveAsFileAction = new QAction(QIcon(":/images/saveAs.png"), tr("Save &As"), this);
    mSaveAsFileAction->setShortcut(QKeySequence::SaveAs);
    mSaveAsFileAction->setStatusTip(tr("Save file as"));
    connect(mSaveAsFileAction, SIGNAL(triggered()), this, SLOT(savePageAs()));

    mExitAction = new QAction(tr("&Exit"), this);
    mExitAction->setShortcut(QKeySequence::Quit);
    mExitAction->setStatusTip(tr("Exit the application"));
    connect(mExitAction, SIGNAL(triggered()), this, SLOT(close()));

    /* Project Actions */
    mNewProjectAction = new QAction(tr("New Project"), this);
    mNewFileAction->setStatusTip(tr("Creates a new Project"));
    connect(mNewProjectAction, SIGNAL(triggered()), this, SLOT(newProject()));

    mOpenProjectAction = new QAction(tr("Open Project"), this);
    mOpenProjectAction->setStatusTip(tr("Open an existing project"));

    mSaveProjectAction = new QAction(tr("Save Project"), this);
    mSaveProjectAction->setStatusTip(tr("Save current project"));

    mSaveProjectAsAction = new QAction(tr("Save Project As"), this);
    mSaveProjectAsAction->setStatusTip(tr("Save current project as"));

    mShowProjectViewAction = new QAction(tr("Show Project View"), this);
    mShowProjectViewAction->setStatusTip(tr("Show Project Settings and Properties"));
    connect(mShowProjectViewAction, SIGNAL(triggered()), this, SLOT(showProjectView()));

    mShowTransistionDiagramAction = new QAction(tr("Show Transistion Diagram"), this);
    mShowTransistionDiagramAction->setStatusTip(tr("Show the Projects Transistion Diagram"));
    connect(mShowTransistionDiagramAction, SIGNAL(triggered()), this, SLOT(showTransistionDiagram()));

    mGenerateHOLAction = new QAction(tr("Generate HOL"), this);
    mGenerateHOLAction->setStatusTip(tr("Generate all the HOL files for the project"));

    mGenerateHaskellAction = new QAction(tr("Generate Haskell"), this);
    mGenerateHaskellAction->setStatusTip(tr("Generate all the Haskell files for the project"));

    mGenerateDocAction = new QAction(tr("Generate Documentation"), this);
    mGenerateDocAction->setStatusTip(tr("Generate Documentation for project"));

    mCloseProjectAction = new QAction(tr("Close project"), this);
    mCloseProjectAction->setStatusTip(tr("Closes the current project"));

    /* Edit Actions */

    mUndoAction = new QAction(tr("&Undo"), this);
    mUndoAction->setShortcut(QKeySequence::Undo);
    mUndoAction->setStatusTip(tr("Undo"));
    connect(mUndoAction, SIGNAL(triggered()), this, SLOT(undo()));

    mRedoAction = new QAction(tr("&Redo"), this);
    mRedoAction->setShortcut(QKeySequence::Redo);
    mRedoAction->setStatusTip(tr("Redo"));
    connect(mRedoAction, SIGNAL(triggered()), this, SLOT(redo()));

    mCutAction = new QAction(tr("&Cut"), this);
    mCutAction->setShortcut(QKeySequence::Cut);
    mCutAction->setStatusTip(tr("Cut"));
    connect(mCutAction, SIGNAL(triggered()), this, SLOT(cut()));

    mCopyAction = new QAction(tr("&Copy"), this);
    mCopyAction->setShortcut(QKeySequence::Copy);
    mCopyAction->setStatusTip(tr("Copy"));
    connect(mCopyAction, SIGNAL(triggered()), this, SLOT(copy()));

    mPasteAction = new QAction(tr("&Paste"), this);
    mPasteAction->setShortcut(QKeySequence::Paste);
    mPasteAction->setStatusTip(tr("Paste"));
    connect(mPasteAction, SIGNAL(triggered()), this, SLOT(paste()));

    mSelectAllAction = new QAction(tr("Select &All"), this);
    mSelectAllAction->setShortcut(QKeySequence::SelectAll);
    mSelectAllAction->setStatusTip(tr("Select All"));
    connect(mSelectAllAction, SIGNAL(triggered()), this, SLOT(selectAll()));

    mFindReplaceAction = new QAction(tr("&Find/Replace"), this);
    mFindReplaceAction->setShortcut(QKeySequence::Find);
    mFindReplaceAction->setStatusTip(tr("Find/Replace"));
    connect(mSelectAllAction, SIGNAL(triggered()), this, SLOT(findReplace()));

    /* HOL Menu Actions */
    mHOLRestartAction = new QAction(tr("Restart HOL"), this);
    mHOLRestartAction->setStatusTip(tr("Restart the HOL buffer"));
    connect(mHOLRestartAction, SIGNAL(triggered()), mHOLWidget, SLOT(restart()));

    mHOLSendRegionToAction = new QAction(tr("Send Region to HOL"), this);
    mHOLSendRegionToAction->setStatusTip(tr("Sends the highlighted region to the HOL buffer"));
    //connect

    mHOLRunHolmakeAction = new QAction(tr("Run Holmake"), this);
    mHOLRunHolmakeAction->setStatusTip(tr("Runs Holamake in current directory"));
    connect(mHOLRunHolmakeAction, SIGNAL(triggered()), this, SLOT(runHolmake()));

    mHOLShowTypesAction = new QAction(tr("Show Types"), this);
    mHOLShowTypesAction->setStatusTip(tr("Show Types"));
    connect(mHOLShowTypesAction, SIGNAL(triggered()), mHOLWidget, SLOT(showTypes()));

    mHOLShowTypesVerboseAction = new QAction(tr("Show Types Verbosely"), this);
    mHOLShowTypesVerboseAction->setStatusTip(tr("Show Types Verbosely"));
    connect(mHOLShowTypesVerboseAction, SIGNAL(triggered()), mHOLWidget, SLOT(showTypesVerbose()));

    mHOLShowNumericalTypesAction = new QAction(tr("Show Numerical Types"), this);
    mHOLShowNumericalTypesAction->setStatusTip(tr("Show Numerical Types"));
    connect(mHOLShowNumericalTypesAction, SIGNAL(triggered()), mHOLWidget, SLOT(showNumericalTypes()));

    mHOLShowAssumptionsAction = new QAction(tr("Show Assumptions"), this);
    mHOLShowAssumptionsAction->setStatusTip(tr("Show Assumptions"));
    connect(mHOLShowAssumptionsAction, SIGNAL(triggered()), mHOLWidget, SLOT(showAssumptions()));

    /* Help Menu Actions */
    mHOLDocumentationAction = new QAction(tr("HOL Documentation"), this);
    mHOLDocumentationAction->setStatusTip(tr("Show HOL Documentation"));

    mAboutAction = new QAction(tr("About"), this);
    mAboutAction->setStatusTip(tr("About"));

    /* Transistion Diagram Actions */
    mAddStateAction = new QAction(tr("Add State"), this);
    mAddStateAction->setStatusTip("Add a new State to the Transistion Diagram");

    mDeleteStateAction = new QAction(tr("Remove State"), this);
    mDeleteStateAction->setStatusTip("Remove state from Transistion Diagram");

    mMakeLinkAction = new QAction(tr("Connect States"), this);
    mMakeLinkAction->setStatusTip("Connect two states");

    mDeleteLinkAction = new QAction(tr("Remove Link"), this);
    mDeleteLinkAction->setStatusTip("Remove the Link between two States");

    mStatePropertiesAction = new QAction(tr("State Properties"), this);
    mStatePropertiesAction->setStatusTip("Display the Properties of the State");

    mZoomInAction = new QAction(tr("Zoom In"), this);
    mZoomInAction->setStatusTip("Zoom In on the Diagrams");

    mZoomOutAction = new QAction(tr("Zoom Out"), this);
    mZoomOutAction->setStatusTip("Zoom Out on the Diagram");
}

void MainWindow::createMenus() {
    mFileMenu = menuBar()->addMenu(tr("&File"));
    mFileMenu->addAction(mNewFileAction);
    mFileMenu->addAction(mOpenFileAction);
    mFileMenu->addSeparator();
    mFileMenu->addAction(mSaveFileAction);
    mFileMenu->addAction(mSaveAsFileAction);
    mFileMenu->addSeparator();
    mFileMenu->addAction(mExitAction);

    mProjectMenu = menuBar()->addMenu(tr("&Project"));
    mProjectMenu->addAction(mNewProjectAction);
    mProjectMenu->addAction(mOpenProjectAction);
    mProjectMenu->addAction(mSaveProjectAction);
    mProjectMenu->addAction(mSaveProjectAsAction);
    mProjectMenu->addSeparator();
    mProjectMenu->addAction(mShowProjectViewAction);
    mProjectMenu->addAction(mShowTransistionDiagramAction);
    mProjectMenu->addSeparator();
    mProjectMenu->addAction(mGenerateHOLAction);
    mProjectMenu->addAction(mGenerateHaskellAction);
    mProjectMenu->addAction(mGenerateDocAction);
    mProjectMenu->addSeparator();
    mProjectMenu->addAction(mCloseProjectAction);

    mEditMenu = menuBar()->addMenu(tr("&Edit"));
    mEditMenu->addAction(mUndoAction);
    mEditMenu->addAction(mRedoAction);
    mEditMenu->addSeparator();
    mEditMenu->addAction(mCutAction);
    mEditMenu->addAction(mCopyAction);
    mEditMenu->addAction(mPasteAction);
    mEditMenu->addSeparator();
    mEditMenu->addAction(mSelectAllAction);
    mEditMenu->addSeparator();
    mEditMenu->addAction(mFindReplaceAction);

    mHOLMenu = menuBar()->addMenu(tr("&HOL"));
    mHOLProcessMenu = mHOLMenu->addMenu(tr("&Process"));
    mHOLGoalMenu = mHOLMenu->addMenu(tr("&Goalstack"));
    mHOLPrintMenu = mHOLMenu->addMenu(tr("Printng Switches"));

    mHOLProcessMenu->addAction(mHOLRestartAction);
    mHOLProcessMenu->addSeparator();
    mHOLProcessMenu->addAction(mHOLSendRegionToAction);
    mHOLProcessMenu->addSeparator();
    mHOLProcessMenu->addAction(mHOLRunHolmakeAction);

    mHOLPrintMenu->addAction(mHOLShowTypesAction);
    mHOLPrintMenu->addAction(mHOLShowTypesVerboseAction);
    mHOLPrintMenu->addAction(mHOLShowNumericalTypesAction);
    mHOLPrintMenu->addAction(mHOLShowAssumptionsAction);
    \
    mHaskellMenu = menuBar()->addMenu(tr("&Haskell"));

    mHelpMenu = menuBar()->addMenu(tr("&Help"));
    mHelpMenu->addAction(mHOLDocumentationAction);
    mHelpMenu->addSeparator();
    mHelpMenu->addAction(mAboutAction);

}

void MainWindow::createToolBars() {

    /* Transistion Diagram */
    mTransistionDiagramToolbar = addToolBar(tr("TransistionDiagram"));
    mTransistionDiagramToolbar->addAction(mAddStateAction);
    mTransistionDiagramToolbar->addAction(mDeleteStateAction);
    mTransistionDiagramToolbar->addAction(mMakeLinkAction);
    mTransistionDiagramToolbar->addAction(mDeleteLinkAction);
    mTransistionDiagramToolbar->addAction(mStatePropertiesAction);
    mTransistionDiagramToolbar->addSeparator();
    mTransistionDiagramToolbar->addAction(mZoomInAction);
    mTransistionDiagramToolbar->addAction(mZoomOutAction);

    /* Edit Toolbar */


    /* Project Toolbar */

}

void MainWindow::createDockWindows() {
    /* Add HOL widget */
    QDockWidget *dock = new QDockWidget(tr("HOL Process"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    mHOLWidget = new HOLWidget;
    dock->setWidget(mHOLWidget);
    addDockWidget(Qt::RightDockWidgetArea, dock);

    /* File System View */
    QDockWidget *fileDock = new QDockWidget(tr("Project"), this);
    fileDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    mFileViewSplitter = new QSplitter;

    QFileSystemModel *fileSystemModel = new QFileSystemModel;
    fileSystemModel->setRootPath(QDir::currentPath());
    QItemSelectionModel *itemSelectionModel = new QItemSelectionModel(fileSystemModel);
    connect(itemSelectionModel, SIGNAL(currentChanged(QModelIndex,QModelIndex)), this, SLOT(fileViewItemSelected(QModelIndex,QModelIndex)));

    QTreeView* tree = new QTreeView(mFileViewSplitter);
    tree->setModel(fileSystemModel);
    tree->setRootIndex(fileSystemModel->index(QDir::currentPath()));
    tree->setSelectionModel(itemSelectionModel);
    tree->hideColumn(2);
    tree->hideColumn(3);
    tree->hideColumn(1);
    fileDock->setWidget(mFileViewSplitter);
    addDockWidget(Qt::RightDockWidgetArea, fileDock);
}

void MainWindow::setStatus(const QString &message) {
    statusBar()->showMessage(message);
}

void MainWindow::save(Page* page) {
    QString fileName = page->getFileName();
    QFile file(fileName);

    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }

    QTextStream out(&file);
    out << page->toPlainText();
    file.close();

    statusBar()->showMessage(tr("File saved"), 2000);
}

void MainWindow::open(const QString &filePath) {
    QFile file(filePath);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("HOLIDE"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(filePath)
                             .arg(file.errorString()));
        return;
    }

    Page* page = addPage(filePath);
    QTextStream in(&file);
    page->setPlainText(in.readAll());
    file.close();
    statusBar()->showMessage(tr("File loaded"), 2000);
}

void MainWindow::undo() {
    int currentTab = mTabWidget->currentIndex();
    Page* page = (Page*)mTabWidget->widget(currentTab);
    page->undo();
}

void MainWindow::redo() {
    int currentTab = mTabWidget->currentIndex();
    Page* page = (Page*)mTabWidget->widget(currentTab);
    page->redo();
}

void MainWindow::cut() {
    int currentTab = mTabWidget->currentIndex();
    Page* page = (Page*)mTabWidget->widget(currentTab);
    page->cut();
}

void MainWindow::copy() {
    int currentTab = mTabWidget->currentIndex();
    Page* page = (Page*)mTabWidget->widget(currentTab);
    page->copy();
}

void MainWindow::paste() {
    int currentTab = mTabWidget->currentIndex();
    Page* page = (Page*)mTabWidget->widget(currentTab);
    page->paste();
}

void MainWindow::selectAll() {
    int currentTab = mTabWidget->currentIndex();
    Page* page = (Page*)mTabWidget->widget(currentTab);
    page->selectAll();
}

void MainWindow::findReplace() {
    /* TODO: Find/Replace Widget */
}

void MainWindow::fileViewItemSelected( const QModelIndex & current, const QModelIndex & previous) {
    Q_UNUSED(previous);
    open(current.data().toString());
}

void MainWindow::runHolmake() {
    QDockWidget *dock = new QDockWidget(tr("HOL Process"), this);
    dock->setAllowedAreas(Qt::BottomDockWidgetArea);
    mHolmakeWidget = new HOLMakeWidget;
    dock->setWidget(mHolmakeWidget);
    addDockWidget(Qt::RightDockWidgetArea, dock);
}

void MainWindow::newProject() {
    qDebug() << "\n[*] MainWindow::newProject";

    if (mProject != NULL) {
        qCritical() << "[-] Project already in Progress";
        exit(1);
    }

    mProject = new Project;

    /* Get Project Name */
    bool ok;
    QString projectName = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                         tr("Enter a Project Name:"), QLineEdit::Normal,
                                         QDir::home().dirName(), &ok);
    if (ok && !projectName.isEmpty())
        mProject->setProjectName(projectName);
    qDebug() << "[+] New Project name: " << projectName;

    /* Setting up directory structure */
    // TODO: Add HOl and Haskell folders, latex
    qDebug() << "[+] Setting up directory structure";
    QDir cur;
    cur.mkdir(projectName);
    cur.cd(projectName);
    mProject->mTopLevel = cur;
    cur.mkdir("xml");
    cur.cd("xml");
    mProject->mXmlFolder = cur;
    qDebug() << "[+] \tTop Level:" << mProject->mTopLevel.path();
    qDebug() << "[+] \tXml: " << mProject->mXmlFolder.path();

    showTransistionDiagram();

    showProjectView();
}

void MainWindow::openProject() {
    qDebug() << "\n[*] MainWindow::openProject";
    QString projectFileName = QFileDialog::getOpenFileName(this, tr("HOLIDE Project File"), QString(), tr("HOLIDE (*.holide *.HOLIDE"));
    mProject = new Project(projectFileName);
}

void MainWindow::saveProject() {}

void MainWindow::saveProjectAs() {}

void MainWindow::saveProjectFile() {
    qDebug () << "\n[*] MainWindow::saveProjectFile";
    /* Update the project */
    // TODO, the child class should handle this?
    mProject->setProjectDescription(mProjectView->getProjectDescription());
    mProject->setPrincipals(mProjectView->getPrincipals());
    mProject->setActions(mProjectView->getActions());
    mProject->setAuthors(mProjectView->getAuthors());

    mProject->saveProjectFile();
}


void MainWindow::showTransistionDiagram() {
    qDebug() << "\n[*] MainWindow::showTransistionDiagram";

    if (mProject == NULL) {
        qCritical() << "[-] Project is not active.";
        return;
    }

    if (mTabWidget->indexOf(mTransistionDiagram) != -1) {
        qDebug() << "[+] Removing Existing Transistion Diagram";
        mTabWidget->removeTab(mTabWidget->indexOf(mTransistionDiagram));
        delete mTransistionDiagram;
    }

    qDebug() << "[+] Opening new Transistion Diagram Tab";
    mTransistionDiagram = new TransistionDiagramWidget(mProject);
    mTabWidget->insertTab(1, mTransistionDiagram, "TransistionDiagram");
    mTabWidget->setCurrentIndex(1);

    qDebug() << "[+] Connecting signals to Transistion Diagram Slots";
    connect(mAddStateAction, SIGNAL(triggered()), mTransistionDiagram, SLOT(addState()));
    connect(mDeleteStateAction, SIGNAL(triggered()), mTransistionDiagram, SLOT(removeSelected()));
    connect(mMakeLinkAction, SIGNAL(triggered()), mTransistionDiagram, SLOT(addLink()));
    connect(mDeleteLinkAction, SIGNAL(triggered()), mTransistionDiagram, SLOT(removeSelected()));
    connect(mZoomInAction, SIGNAL(triggered()), mTransistionDiagram, SLOT(zoomIn()));
    connect(mZoomOutAction, SIGNAL(triggered()), mTransistionDiagram, SLOT(zoomOut()));
}

void MainWindow::showProjectView() {
    qDebug() << "\n[*] MainWindow::showProjectView";

    if (mProject == NULL) {
        qCritical() << "[-] Project is not active.";
        return;
    }

    if (mTabWidget->indexOf(mProjectView) != -1) {
        qDebug() << "[+] Removing Existing ProjectView";
        mTabWidget->removeTab(mTabWidget->indexOf(mProjectView));
        delete mProjectView;
    }

    qDebug() << "[+] Opening new Project Tab";
    mProjectView = new ProjectView(mProject);
    mTabWidget->insertTab(0, mProjectView, "Project View");
    mTabWidget->setCurrentIndex(0);
}
