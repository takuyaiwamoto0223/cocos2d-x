// Application application cpp file.
 
// Original file name: HelloWorldApp.cpp
// Generated by TOPS Builder:Project wizard,Date:2010-8-3

#include  "HelloWorldApp.h"

#include "cocos2d.h"
using namespace cocos2d;

#define IMG_PATH        "/NEWPLUS/TDA_DATA/UserData/HelloWorld.png"

THelloWorldApp::THelloWorldApp() 
: m_rcWnd(0, 0, GetScreenWidth(), GetScreenHeight())
, m_pMainWnd(NULL)
{

}

Boolean THelloWorldApp::initCocos2d()
{
    // init director
    CCDirector::getSharedDirector()->setOpenGLView(m_pMainWnd);
    CCDirector::getSharedDirector()->setDeviceOrientation(kCCDeviceOrientationLandscapeLeft);

    // load background image texture and get window size
    CCTexture2D * pTexture = CCTextureCache::sharedTextureCache()->addImage(IMG_PATH);
    CGSize size = CCDirector::getSharedDirector()->getWinSize();

    // create sprite instance
    CCSprite * pSprite = (new CCSprite())->initWithTexture(pTexture); 
    pSprite->setPosition(CGPoint(size.width / 2, size.height / 2));
    pSprite->autorelease()->retain();

    // create layer instance
    CCLayer * pLayer = new CCLayer();
    pLayer->addChild(pSprite)->autorelease();

    // add layer to scene
    CCScene * pScene = CCScene::node();
    pScene->addChild(pLayer);

    // add scene to director
    CCDirector::getSharedDirector()->runWithScene(pScene);
    return TRUE;
}

Boolean  THelloWorldApp::EventHandler(EventType*  pEvent)
{
	Boolean     bHandled = FALSE;
	switch(pEvent->eType)
	{
	case EVENT_AppLoad:
        if (! (m_pMainWnd = new CCXEGLView(this)) || ! m_pMainWnd->Create(&m_rcWnd))
        {
        	// create window failed, quit application
            SendStopEvent();
            bHandled = TRUE;
            break;
        }
        SetActiveWindow(m_pMainWnd);
        // do not return bHandle equal TRUE, CCXApplication::EventHandler need do some thing.
		break;
	}
    return (bHandled) ? TRUE : CCXApplication::EventHandler(pEvent);
}

// application main entry
Int32 TG3AppMain(const TUChar * pAppID, UInt32 nCmd, void * pCmdParam)
{
    THelloWorldApp app;
    return app.Run();
}
