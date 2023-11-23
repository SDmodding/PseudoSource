// File Line: 55
// RVA: 0x202E20
void __fastcall UFG::Editor::ValueChange::ValueChange(UFG::Editor::ValueChange *this)
{
  __int64 v2; // rax
  float *mValue; // rdx

  this->mType = NONE;
  UFG::qPropertyPath::qPropertyPath(&this->mPath);
  *(_QWORD *)&this->mNewItemType = 29i64;
  v2 = 0i64;
  mValue = this->mVectoredValue.mValue;
  do
  {
    this->mVectoredValue.mbValid[v2] = 0;
    *mValue = 0.0;
    ++v2;
    ++mValue;
  }
  while ( v2 < 16 );
  this->mVectoredValue.mbGimbalLock = 0;
  this->mSimpleValue.meType = UID_Invalid;
  UFG::qString::qString(&this->mSimpleValue.mValueString);
  *(_QWORD *)&this->mSimpleValue.mValueSymbol.mUID = -1i64;
  this->mSimpleValue.mValueWiseSymbol.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
}

// File Line: 85
// RVA: 0x2038A0
void __fastcall UFG::Editor::PropertyProxy::~PropertyProxy(UFG::Editor::PropertyProxy *this)
{
  UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy> *v1; // rdx
  UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy> *mPrev; // rcx
  UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy> *mNext; // rax

  this->vfptr = (UFG::Editor::PropertyProxyVtbl *)&UFG::Editor::PropertyProxy::`vftable;
  v1 = &this->UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy>;
  mPrev = this->mPrev;
  mNext = v1->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
}

// File Line: 107
// RVA: 0x203920
void __fastcall UFG::Editor::PropertyProxySimple::~PropertyProxySimple(UFG::Editor::PropertyProxySimple *this)
{
  const char **p; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy> *v5; // rcx
  UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy> *v6; // rax

  this->vfptr = (UFG::Editor::PropertyProxyVtbl *)&UFG::Editor::PropertyProxySimple::`vftable;
  p = this->mSuggestions.p;
  if ( p )
    operator delete[](p);
  this->mSuggestions.p = 0i64;
  *(_QWORD *)&this->mSuggestions.size = 0i64;
  UFG::qList<UFG::qString,UFG::qString,1,0>::DeleteNodes(&this->mSuggestionList);
  mPrev = this->mSuggestionList.mNode.mPrev;
  mNext = this->mSuggestionList.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mSuggestionList.mNode.mPrev = &this->mSuggestionList.mNode;
  this->mSuggestionList.mNode.mNext = &this->mSuggestionList.mNode;
  UFG::qString::~qString(&this->mValueString);
  this->vfptr = (UFG::Editor::PropertyProxyVtbl *)&UFG::Editor::PropertyProxy::`vftable;
  v5 = this->mPrev;
  v6 = this->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  this->mPrev = &this->UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy>;
  this->mNext = &this->UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy>;
}

// File Line: 166
// RVA: 0x203A50
void __fastcall UFG::Editor::PropertyProxy_PropertySet::~PropertyProxy_PropertySet(
        UFG::Editor::PropertyProxy_PropertySet *this)
{
  this->vfptr = (UFG::Editor::PropertyProxyVtbl *)&UFG::Editor::PropertyProxy_PropertySet::`vftable;
  UFG::qString::~qString(&this->mNewPropertyName);
  UFG::Editor::PropertyProxy_Container::~PropertyProxy_Container(this);
}

// File Line: 288
// RVA: 0x202280
void __fastcall UFG::Editor::PropertyBrowserWindow::PropertyBrowserWindow(
        UFG::Editor::PropertyBrowserWindow *this,
        MemImageLoadFlag f)
{
  UFG::DUIWindow::DUIWindow(this, f);
  this->UFG::qReflectObjectType<UFG::Editor::PropertyBrowserWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::PropertyBrowserWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::PropertyBrowserWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::PropertyBrowserWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->UFG::qReflectObjectType<UFG::Editor::PropertyBrowserWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::PropertyBrowserWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::PropertyBrowserWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::PropertyBrowserWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  UFG::Editor::PropertyBrowser::PropertyBrowser(&this->mBrowser);
  UFG::qString::qString(&this->mLockedSelection);
  UFG::qString::qString(&this->mDefaultSelection);
  UFG::Editor::PropertyBrowserWindow::Init(this);
}

// File Line: 289
// RVA: 0x202300
void __fastcall UFG::Editor::PropertyBrowserWindow::PropertyBrowserWindow(UFG::Editor::PropertyBrowserWindow *this)
{
  UFG::DUIWindow::DUIWindow(this);
  this->UFG::qReflectObjectType<UFG::Editor::PropertyBrowserWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::PropertyBrowserWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::PropertyBrowserWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::PropertyBrowserWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mBaseNode.mUID = -1i64;
  this->mTypeUID = UFG::qStringHash64("UFG::Editor::PropertyBrowserWindow", 0xFFFFFFFFFFFFFFFFui64);
  this->UFG::qReflectObjectType<UFG::Editor::PropertyBrowserWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::PropertyBrowserWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::PropertyBrowserWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::PropertyBrowserWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  UFG::Editor::PropertyBrowser::PropertyBrowser(&this->mBrowser);
  UFG::qString::qString(&this->mLockedSelection);
  UFG::qString::qString(&this->mDefaultSelection);
  UFG::Editor::PropertyBrowserWindow::Init(this);
  this->mRect.mW = 420;
  this->mRect.mH = 650;
}

