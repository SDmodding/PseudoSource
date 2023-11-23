// File Line: 53
// RVA: 0x153ED0
void __fastcall UFG::PartCustomizer::PartCustomizer(UFG::PartCustomizer *this, MemImageLoadFlag f)
{
  unsigned __int64 v3; // rax

  UFG::DUIWindow::DUIWindow(this, f);
  this->UFG::qReflectObjectType<UFG::PartCustomizer,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::PartCustomizer,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::PartCustomizer,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::PartCustomizer,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->UFG::qReflectObjectType<UFG::PartCustomizer,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::PartCustomizer::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::PartCustomizer,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::PartCustomizer::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v3 = UFG::qStringHash64("UFG::PartDefinition", 0xFFFFFFFFFFFFFFFFui64);
  UFG::EditNotification::EditNotification(
    &this->mNotification,
    v3,
    UFG::PartCustomizer::OnPropertyChanged,
    (void (__fastcall *)(char *, void *))_,
    0i64);
  this->mSelectedParts.mNode.mPrev = &this->mSelectedParts.mNode;
  this->mSelectedParts.mNode.mNext = &this->mSelectedParts.mNode;
  *(_QWORD *)&this->mCurrentPartTemplate = 0i64;
  this->mCurrentPartEditIndex = 0;
  *(_DWORD *)&this->mCollapseTemplate = 16843009;
  *(_DWORD *)&this->mCollapseDiffuseChannels = 257;
  *(_WORD *)&this->mCompositeDirty = 0;
  UFG::PartLoader::PartLoader(&this->mPartLoader);
  this->mSimObject = 0i64;
  this->mInstance = 0i64;
  UFG::qString::Set(&this->mTitle, "PartCustomizer");
  this->mScrollPos = 0i64;
  *(_QWORD *)&this->mRect.mX = 0i64;
  this->mRect.mW = 400;
  this->mRect.mH = 720;
  this->mNotification.mUserData = this;
  UFG::PartCustomizer::sInstance = this;
}

