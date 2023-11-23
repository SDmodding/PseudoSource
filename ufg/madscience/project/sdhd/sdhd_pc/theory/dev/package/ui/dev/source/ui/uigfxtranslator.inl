// File Line: 25
// RVA: 0x5C3CA0
void __fastcall UFG::UIDictionary::UIDictionary(UFG::UIDictionary *this, char *sectionName)
{
  this->mPrev = this;
  this->mNext = this;
  this->mUID = 0;
  this->mStringData = 0i64;
  *(_WORD *)&this->mIsLoaded = 0;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mStringMap.mTree);
  this->mhLocalizationData.mPrev = &this->mhLocalizationData;
  this->mhLocalizationData.mNext = &this->mhLocalizationData;
  this->mhLocalizationData.mCallback = 0i64;
  this->mhLocalizationData.mCallbackParam = 0i64;
  this->mhLocalizationData.mImpl = 0i64;
  *(_DWORD *)&this->mhLocalizationData.mFlags = 536870915;
  this->mhLocalizationData._mTargetState.mValue = 1;
  UFG::qResourceHandle::qResourceHandle(&this->mDatabaseHandle);
  this->mUID = UFG::qStringHashUpper32(sectionName, -1);
  this->mFilename[0] = 0;
  UFG::qStringCopy(this->mSectionName, 128, sectionName, -1);
}

// File Line: 35
// RVA: 0x5C9340
void __fastcall UFG::UIDictionary::~UIDictionary(UFG::UIDictionary *this)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v3; // rax
  Render::SkinningCacheNode *Head; // rbx
  UFG::qNode<UFG::UIDictionary,UFG::UIDictionary> *mPrev; // rcx
  UFG::qNode<UFG::UIDictionary,UFG::UIDictionary> *mNext; // rax

  UFG::UIDictionary::UnloadDictionary(this);
  Inventory = `UFG::qGetResourceInventory<UFG::UILocalizationChunk>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::UILocalizationChunk>::`2::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v3, 0x90CE6B7A);
    `UFG::qGetResourceInventory<UFG::UILocalizationChunk>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&this->mDatabaseHandle, Inventory);
  UFG::qResourceHandle::~qResourceHandle(&this->mDatabaseHandle);
  UFG::DataStreamer::Handle::~Handle(&this->mhLocalizationData);
  while ( this->mStringMap.mTree.mCount )
  {
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mStringMap);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mStringMap,
      &Head->mNode);
    UFG::qMemoryPool::Free(&gScaleformMemoryPool, (char *)Head);
  }
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&this->mStringMap);
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 84
// RVA: 0x5C3D70
void __fastcall UFG::UIGfxTranslator::UIGfxTranslator(UFG::UIGfxTranslator *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::State::`vftable;
  this->SType = State_BlendMode;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::Translator::`vftable;
  this->WWMode = 0;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&UFG::UIGfxTranslator::`vftable;
  this->mLanguage = eLang_Invalid;
  *(_QWORD *)&this->mFontScale = 1065353216i64;
  this->mDateFormat = 2;
  this->mDecimals = 2;
  *(_WORD *)&this->mSymbolPrefixNumber = 1;
  this->mIsAcceptButtonSwapped = 0;
  this->mDictionaries.mNode.mPrev = &this->mDictionaries.mNode;
  this->mDictionaries.mNode.mNext = &this->mDictionaries.mNode;
  UFG::qStringCopy(this->mCurrencySymbol, 0x7FFFFFFF, "$", -1);
  UFG::qStringCopy(this->mThousandsSeparator, 0x7FFFFFFF, ",", -1);
  UFG::qStringCopy(this->mDecimalSymbol, 0x7FFFFFFF, ".", -1);
}

// File Line: 94
// RVA: 0x5C9430
void __fastcall UFG::UIGfxTranslator::~UIGfxTranslator(UFG::UIGfxTranslator *this)
{
  UFG::qList<UFG::UIDictionary,UFG::UIDictionary,1,0> *p_mDictionaries; // rbx
  UFG::qNode<UFG::UIDictionary,UFG::UIDictionary> *mPrev; // rcx
  UFG::qNode<UFG::UIDictionary,UFG::UIDictionary> *mNext; // rax

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&UFG::UIGfxTranslator::`vftable;
  this->mGfxLoader = 0i64;
  p_mDictionaries = &this->mDictionaries;
  UFG::qList<UFG::UIDictionary,UFG::UIDictionary,1,0>::DeleteNodes(&this->mDictionaries);
  mPrev = p_mDictionaries->mNode.mPrev;
  mNext = p_mDictionaries->mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_mDictionaries->mNode.mPrev = &p_mDictionaries->mNode;
  p_mDictionaries->mNode.mNext = &p_mDictionaries->mNode;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::State::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

