// File Line: 53
// RVA: 0x153ED0
void __fastcall UFG::PartCustomizer::PartCustomizer(UFG::PartCustomizer *this, MemImageLoadFlag f)
{
  UFG::PartCustomizer *v2; // rbx
  unsigned __int64 v3; // rax
  UFG::qList<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper,1,0> *v4; // [rsp+60h] [rbp+18h]

  v2 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr, f);
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::PartCustomizer,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::PartCustomizer,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::PartCustomizer::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::PartCustomizer::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v3 = UFG::qStringHash64("UFG::PartDefinition", 0xFFFFFFFFFFFFFFFFui64);
  UFG::EditNotification::EditNotification(
    &v2->mNotification,
    v3,
    UFG::PartCustomizer::OnPropertyChanged,
    (void (__fastcall *)(char *, void *))_,
    0i64);
  v4 = &v2->mSelectedParts;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
  *(_QWORD *)&v2->mCurrentPartTemplate = 0i64;
  v2->mCurrentPartEditIndex = 0;
  *(_DWORD *)&v2->mCollapseTemplate = 16843009;
  *(_DWORD *)&v2->mCollapseDiffuseChannels = 257;
  *(_WORD *)&v2->mCompositeDirty = 0;
  UFG::PartLoader::PartLoader(&v2->mPartLoader);
  v2->mSimObject = 0i64;
  v2->mInstance = 0i64;
  UFG::qString::Set(&v2->mTitle, "PartCustomizer");
  v2->mScrollPos = 0i64;
  *(_QWORD *)&v2->mRect.mX = 0i64;
  v2->mRect.mW = 400;
  v2->mRect.mH = 720;
  v2->mNotification.mUserData = v2;
  UFG::PartCustomizer::sInstance = v2;
}

