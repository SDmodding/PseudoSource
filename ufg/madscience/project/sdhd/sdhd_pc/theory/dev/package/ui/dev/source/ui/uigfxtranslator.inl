// File Line: 25
// RVA: 0x5C3CA0
void __fastcall UFG::UIDictionary::UIDictionary(UFG::UIDictionary *this, const char *sectionName)
{
  const char *v2; // rbx
  UFG::UIDictionary *v3; // rdi
  UFG::DataStreamer::Handle *v4; // [rsp+50h] [rbp+18h]

  v2 = sectionName;
  v3 = this;
  this->mPrev = (UFG::qNode<UFG::UIDictionary,UFG::UIDictionary> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::UIDictionary,UFG::UIDictionary> *)&this->mPrev;
  this->mUID = 0;
  this->mStringData = 0i64;
  *(_WORD *)&this->mIsLoaded = 0;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mStringMap.mTree);
  v4 = &v3->mhLocalizationData;
  v4->mPrev = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)&v4->mPrev;
  v3->mhLocalizationData.mCallback = 0i64;
  v3->mhLocalizationData.mCallbackParam = 0i64;
  v3->mhLocalizationData.mImpl = 0i64;
  *(_DWORD *)&v3->mhLocalizationData.mFlags = 536870915;
  v3->mhLocalizationData._mTargetState.mValue = 1;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v3->mDatabaseHandle.mPrev);
  v3->mUID = UFG::qStringHashUpper32(v2, 0xFFFFFFFF);
  v3->mFilename[0] = 0;
  UFG::qStringCopy(v3->mSectionName, 128, v2, -1);
}

// File Line: 35
// RVA: 0x5C9340
void __fastcall UFG::UIDictionary::~UIDictionary(UFG::UIDictionary *this)
{
  UFG::UIDictionary *v1; // rdi
  UFG::qResourceInventory *v2; // rax
  UFG::qResourceWarehouse *v3; // rax
  Render::SkinningCacheNode *v4; // rbx
  UFG::qNode<UFG::UIDictionary,UFG::UIDictionary> *v5; // rcx
  UFG::qNode<UFG::UIDictionary,UFG::UIDictionary> *v6; // rax

  v1 = this;
  UFG::UIDictionary::UnloadDictionary(this);
  v2 = `UFG::qGetResourceInventory<UFG::UILocalizationChunk>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::UILocalizationChunk>::`2::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    v2 = UFG::qResourceWarehouse::GetInventory(v3, 0x90CE6B7A);
    `UFG::qGetResourceInventory<UFG::UILocalizationChunk>::`2::result = v2;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mDatabaseHandle.mPrev, v2);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mDatabaseHandle.mPrev);
  UFG::DataStreamer::Handle::~Handle(&v1->mhLocalizationData);
  while ( v1->mStringMap.mTree.mCount )
  {
    v4 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mStringMap);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v1->mStringMap,
      &v4->mNode);
    UFG::qMemoryPool::Free(&gScaleformMemoryPool, v4);
  }
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&v1->mStringMap);
  v5 = v1->mPrev;
  v6 = v1->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v1->mPrev = (UFG::qNode<UFG::UIDictionary,UFG::UIDictionary> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::UIDictionary,UFG::UIDictionary> *)&v1->mPrev;
}

// File Line: 84
// RVA: 0x5C3D70
void __fastcall UFG::UIGfxTranslator::UIGfxTranslator(UFG::UIGfxTranslator *this)
{
  UFG::UIGfxTranslator *v1; // rbx
  UFG::qList<UFG::UIDictionary,UFG::UIDictionary,1,0> *v2; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::State::`vftable;
  this->SType = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::Translator::`vftable;
  this->WWMode = 0;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&UFG::UIGfxTranslator::`vftable;
  this->mLanguage = -1;
  *(_QWORD *)&this->mFontScale = 1065353216i64;
  this->mDateFormat = 2;
  this->mDecimals = 2;
  *(_WORD *)&this->mSymbolPrefixNumber = 1;
  this->mIsAcceptButtonSwapped = 0;
  v2 = &this->mDictionaries;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  UFG::qStringCopy(this->mCurrencySymbol, 0x7FFFFFFF, "$", -1);
  UFG::qStringCopy(v1->mThousandsSeparator, 0x7FFFFFFF, ",", -1);
  UFG::qStringCopy(v1->mDecimalSymbol, 0x7FFFFFFF, ".", -1);
}

// File Line: 94
// RVA: 0x5C9430
void __fastcall UFG::UIGfxTranslator::~UIGfxTranslator(UFG::UIGfxTranslator *this)
{
  UFG::UIGfxTranslator *v1; // rdi
  UFG::qList<UFG::UIDictionary,UFG::UIDictionary,1,0> *v2; // rbx
  UFG::qNode<UFG::UIDictionary,UFG::UIDictionary> *v3; // rcx
  UFG::qNode<UFG::UIDictionary,UFG::UIDictionary> *v4; // rax

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&UFG::UIGfxTranslator::`vftable;
  this->mGfxLoader = 0i64;
  v2 = &this->mDictionaries;
  UFG::qList<UFG::UIDictionary,UFG::UIDictionary,1,0>::DeleteNodes(&this->mDictionaries);
  v3 = v2->mNode.mPrev;
  v4 = v2->mNode.mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::State::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
}

