// File Line: 55
// RVA: 0x202E20
void __fastcall UFG::Editor::ValueChange::ValueChange(UFG::Editor::ValueChange *this)
{
  UFG::Editor::ValueChange *v1; // rdi
  signed __int64 v2; // rax
  _DWORD *v3; // rdx

  v1 = this;
  this->mType = 0;
  UFG::qPropertyPath::qPropertyPath(&this->mPath);
  *(_QWORD *)&v1->mNewItemType = 29i64;
  v2 = 0i64;
  v3 = (_DWORD *)v1->mVectoredValue.mValue;
  do
  {
    v1->mVectoredValue.mbValid[v2] = 0;
    *v3 = 0;
    ++v2;
    ++v3;
  }
  while ( v2 < 16 );
  v1->mVectoredValue.mbGimbalLock = 0;
  v1->mSimpleValue.meType = 29;
  UFG::qString::qString(&v1->mSimpleValue.mValueString);
  *(_QWORD *)&v1->mSimpleValue.mValueSymbol.mUID = -1i64;
  v1->mSimpleValue.mValueWiseSymbol.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
}

// File Line: 85
// RVA: 0x2038A0
void __fastcall UFG::Editor::PropertyProxy::~PropertyProxy(UFG::Editor::PropertyProxy *this)
{
  UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy> *v1; // rdx
  UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy> *v2; // rcx
  UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy> *v3; // rax

  this->vfptr = (UFG::Editor::PropertyProxyVtbl *)&UFG::Editor::PropertyProxy::`vftable;
  v1 = (UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy> *)&this->mPrev;
  v2 = this->mPrev;
  v3 = v1->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mPrev = v1;
  v1->mNext = v1;
}

// File Line: 107
// RVA: 0x203920
void __fastcall UFG::Editor::PropertyProxySimple::~PropertyProxySimple(UFG::Editor::PropertyProxySimple *this)
{
  UFG::Editor::PropertyProxySimple *v1; // rdi
  const char **v2; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v3; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v4; // rax
  UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy> *v5; // rdx
  UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy> *v6; // rcx
  UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy> *v7; // rax

  v1 = this;
  this->vfptr = (UFG::Editor::PropertyProxyVtbl *)&UFG::Editor::PropertyProxySimple::`vftable;
  v2 = this->mSuggestions.p;
  if ( v2 )
    operator delete[](v2);
  v1->mSuggestions.p = 0i64;
  *(_QWORD *)&v1->mSuggestions.size = 0i64;
  UFG::qList<UFG::qString,UFG::qString,1,0>::DeleteNodes(&v1->mSuggestionList);
  v3 = v1->mSuggestionList.mNode.mPrev;
  v4 = v1->mSuggestionList.mNode.mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v1->mSuggestionList.mNode.mPrev = &v1->mSuggestionList.mNode;
  v1->mSuggestionList.mNode.mNext = &v1->mSuggestionList.mNode;
  UFG::qString::~qString(&v1->mValueString);
  v1->vfptr = (UFG::Editor::PropertyProxyVtbl *)&UFG::Editor::PropertyProxy::`vftable;
  v5 = (UFG::qNode<UFG::Editor::PropertyProxy,UFG::Editor::PropertyProxy> *)&v1->mPrev;
  v6 = v1->mPrev;
  v7 = v1->mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v5->mPrev = v5;
  v5->mNext = v5;
}

// File Line: 166
// RVA: 0x203A50
void __fastcall UFG::Editor::PropertyProxy_PropertySet::~PropertyProxy_PropertySet(UFG::Editor::PropertyProxy_PropertySet *this)
{
  UFG::Editor::PropertyProxy_PropertySet *v1; // rbx

  v1 = this;
  this->vfptr = (UFG::Editor::PropertyProxyVtbl *)&UFG::Editor::PropertyProxy_PropertySet::`vftable;
  UFG::qString::~qString(&this->mNewPropertyName);
  UFG::Editor::PropertyProxy_Container::~PropertyProxy_Container((UFG::Editor::PropertyProxy_Container *)&v1->vfptr);
}

// File Line: 288
// RVA: 0x202280
void __fastcall UFG::Editor::PropertyBrowserWindow::PropertyBrowserWindow(UFG::Editor::PropertyBrowserWindow *this, MemImageLoadFlag f)
{
  UFG::Editor::PropertyBrowserWindow *v2; // rbx

  v2 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr, f);
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::PropertyBrowserWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::PropertyBrowserWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::PropertyBrowserWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::PropertyBrowserWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  UFG::Editor::PropertyBrowser::PropertyBrowser(&v2->mBrowser);
  UFG::qString::qString(&v2->mLockedSelection);
  UFG::qString::qString(&v2->mDefaultSelection);
  UFG::Editor::PropertyBrowserWindow::Init(v2);
}

// File Line: 289
// RVA: 0x202300
void __fastcall UFG::Editor::PropertyBrowserWindow::PropertyBrowserWindow(UFG::Editor::PropertyBrowserWindow *this)
{
  UFG::Editor::PropertyBrowserWindow *v1; // rbx

  v1 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::PropertyBrowserWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::PropertyBrowserWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v1->mBaseNode.mUID = -1i64;
  v1->mTypeUID = UFG::qStringHash64("UFG::Editor::PropertyBrowserWindow", 0xFFFFFFFFFFFFFFFFui64);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::PropertyBrowserWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::PropertyBrowserWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  UFG::Editor::PropertyBrowser::PropertyBrowser(&v1->mBrowser);
  UFG::qString::qString(&v1->mLockedSelection);
  UFG::qString::qString(&v1->mDefaultSelection);
  UFG::Editor::PropertyBrowserWindow::Init(v1);
  v1->mRect.mW = 420;
  v1->mRect.mH = 650;
}

