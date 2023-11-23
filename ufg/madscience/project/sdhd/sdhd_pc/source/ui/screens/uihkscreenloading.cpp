// File Line: 22
// RVA: 0x1566E00
__int64 dynamic_initializer_for__UFG::UIHKScreenLoading::gTexturePackFilename__()
{
  UFG::qString::qString(&UFG::UIHKScreenLoading::gTexturePackFilename);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UIHKScreenLoading::gTexturePackFilename__);
}

// File Line: 25
// RVA: 0x5CB3B0
void __fastcall UFG::UIHKScreenLoading::~UIHKScreenLoading(UFG::UIHKScreenLoading *this)
{
  UFG::UIScreenTextureManager *v2; // rax

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenLoading::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "Loading");
  UFG::UIScreen::~UIScreen(this);
}

// File Line: 40
// RVA: 0x6325E0
void __fastcall UFG::UIHKScreenLoading::init(UFG::UIHKScreenLoading *this, UFG::UICommandData *data)
{
  Scaleform::GFx::Movie *pObject; // rdi
  UFG::GameStatTracker *v3; // rax
  UFG::PersistentData::String *Stat; // rax
  int mLength; // r8d
  UFG::GameStatTracker *v6; // rax
  UFG::PersistentData::String *v7; // rax
  int v8; // r8d
  UFG::GameStatTracker *v9; // rax
  UFG::PersistentData::String *v10; // rax
  int v11; // r8d
  UFG::GameStatTracker *v12; // rax
  UFG::GameStatTracker *v13; // rax
  UFG::GameStatTracker *v14; // rax
  UFG::GameStatTracker *v15; // rax
  UFG::qArray<unsigned long,0> *MapInt; // rbx
  unsigned __int64 Ticks; // rsi
  unsigned int v18; // eax
  unsigned int Int; // eax
  char *mData; // rbx
  UFG::qString v21; // [rsp+28h] [rbp-39h] BYREF
  UFG::qString string; // [rsp+50h] [rbp-11h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+78h] [rbp+17h] BYREF
  __int64 v24; // [rsp+A8h] [rbp+47h]

  v24 = -2i64;
  pObject = this->mRenderable->m_movie.pObject;
  if ( !pObject )
    return;
  UFG::qString::qString(&v21);
  v3 = UFG::GameStatTracker::Instance();
  Stat = UFG::GameStatTracker::GetStat(v3, LoadingHintPriority0);
  mLength = Stat->mValue.mLength;
  if ( mLength )
  {
    UFG::qString::Set(&v21, Stat->mValue.mData, mLength, 0i64, 0);
    UFG::qString::qString(&string, &customCaption);
    v14 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v14, LoadingHintPriority0, &string);
    goto LABEL_8;
  }
  v6 = UFG::GameStatTracker::Instance();
  v7 = UFG::GameStatTracker::GetStat(v6, LoadingHintPriority1);
  v8 = v7->mValue.mLength;
  if ( v8 )
  {
    UFG::qString::Set(&v21, v7->mValue.mData, v8, 0i64, 0);
    UFG::qString::qString(&string, &customCaption);
    v13 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v13, LoadingHintPriority1, &string);
    goto LABEL_8;
  }
  v9 = UFG::GameStatTracker::Instance();
  v10 = UFG::GameStatTracker::GetStat(v9, LoadingHintPriority2);
  v11 = v10->mValue.mLength;
  if ( v11 )
  {
    UFG::qString::Set(&v21, v10->mValue.mData, v11, 0i64, 0);
    UFG::qString::qString(&string, &customCaption);
    v12 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v12, LoadingHintPriority2, &string);
LABEL_8:
    UFG::qString::~qString(&string);
  }
  if ( !v21.mLength )
  {
    v15 = UFG::GameStatTracker::Instance();
    MapInt = (UFG::qArray<unsigned long,0> *)UFG::GameStatTracker::GetMapInt(v15, UnlockedLoadingHints);
    Ticks = UFG::qGetTicks();
    v18 = UFG::qSymbolUC::as_uint32(MapInt);
    if ( v18 )
    {
      Int = UFG::PersistentData::MapInt::GetInt((UFG::PersistentData::MapInt *)MapInt, Ticks / 0x2710 % v18);
      if ( Int == 3 )
        UFG::qString::Set(&v21, "$UNLOCKABLE_LOADING_HINT_003_PC");
      else
        UFG::qString::Format(&v21, "$UNLOCKABLE_LOADING_HINT_%03d", Int);
    }
    else
    {
      UFG::qString::Format(&v21, "NO GENERIC HINTS TO DISPLAY", 0i64);
    }
  }
  `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  mData = v21.mData;
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = VT_String;
  ptr.mValue.pString = mData;
  Scaleform::GFx::Movie::Invoke(pObject, "Set_Text", 0i64, &ptr, 1u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  UFG::qString::~qString(&v21);
}

