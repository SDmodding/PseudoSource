// File Line: 22
// RVA: 0x1566E00
__int64 dynamic_initializer_for__UFG::UIHKScreenLoading::gTexturePackFilename__()
{
  UFG::qString::qString(&UFG::UIHKScreenLoading::gTexturePackFilename);
  return atexit(dynamic_atexit_destructor_for__UFG::UIHKScreenLoading::gTexturePackFilename__);
}

// File Line: 25
// RVA: 0x5CB3B0
void __fastcall UFG::UIHKScreenLoading::~UIHKScreenLoading(UFG::UIHKScreenLoading *this)
{
  UFG::UIHKScreenLoading *v1; // rbx
  UFG::UIScreenTextureManager *v2; // rax

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenLoading::`vftable';
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "Loading");
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 40
// RVA: 0x6325E0
void __fastcall UFG::UIHKScreenLoading::init(UFG::UIHKScreenLoading *this, UFG::UICommandData *data)
{
  Scaleform::GFx::Movie *v2; // rdi
  UFG::GameStatTracker *v3; // rax
  UFG::qString *v4; // rax
  int v5; // er8
  UFG::GameStatTracker *v6; // rax
  UFG::qString *v7; // rax
  int v8; // er8
  UFG::GameStatTracker *v9; // rax
  UFG::qString *v10; // rax
  int v11; // er8
  UFG::GameStatTracker *v12; // rax
  UFG::GameStatTracker *v13; // rax
  UFG::GameStatTracker *v14; // rax
  UFG::GameStatTracker *v15; // rax
  UFG::qArray<unsigned long,0> *v16; // rbx
  unsigned __int64 v17; // rsi
  unsigned int v18; // eax
  unsigned int v19; // eax
  char *v20; // rbx
  UFG::qString v21; // [rsp+28h] [rbp-39h]
  UFG::qString string; // [rsp+50h] [rbp-11h]
  char ptr; // [rsp+78h] [rbp+17h]
  __int64 v24; // [rsp+88h] [rbp+27h]
  unsigned int v25; // [rsp+90h] [rbp+2Fh]
  char *v26; // [rsp+98h] [rbp+37h]
  __int64 v27; // [rsp+A8h] [rbp+47h]

  v27 = -2i64;
  v2 = this->mRenderable->m_movie.pObject;
  if ( !v2 )
    return;
  UFG::qString::qString(&v21);
  v3 = UFG::GameStatTracker::Instance();
  v4 = UFG::GameStatTracker::GetStat(v3, 0);
  v5 = v4->mLength;
  if ( v5 )
  {
    UFG::qString::Set(&v21, v4->mData, v5, 0i64, 0);
    UFG::qString::qString(&string, &customWorldMapCaption);
    v14 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v14, 0, &string);
    goto LABEL_8;
  }
  v6 = UFG::GameStatTracker::Instance();
  v7 = UFG::GameStatTracker::GetStat(v6, LoadingHintPriority1);
  v8 = v7->mLength;
  if ( v8 )
  {
    UFG::qString::Set(&v21, v7->mData, v8, 0i64, 0);
    UFG::qString::qString(&string, &customWorldMapCaption);
    v13 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v13, LoadingHintPriority1, &string);
    goto LABEL_8;
  }
  v9 = UFG::GameStatTracker::Instance();
  v10 = UFG::GameStatTracker::GetStat(v9, LoadingHintPriority2);
  v11 = v10->mLength;
  if ( v11 )
  {
    UFG::qString::Set(&v21, v10->mData, v11, 0i64, 0);
    UFG::qString::qString(&string, &customWorldMapCaption);
    v12 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v12, LoadingHintPriority2, &string);
LABEL_8:
    UFG::qString::~qString(&string);
  }
  if ( !v21.mLength )
  {
    v15 = UFG::GameStatTracker::Instance();
    v16 = (UFG::qArray<unsigned long,0> *)UFG::GameStatTracker::GetMapInt(v15, UnlockedLoadingHints);
    v17 = UFG::qGetTicks();
    v18 = UFG::qSymbolUC::as_uint32(v16);
    if ( v18 )
    {
      v19 = UFG::PersistentData::MapInt::GetInt(
              (UFG::PersistentData::MapInt *)v16,
              ((unsigned __int64)(v17 * (unsigned __int128)0x346DC5D63886594Bui64 >> 64) >> 11) % v18);
      if ( v19 == 3 )
        UFG::qString::Set(&v21, "$UNLOCKABLE_LOADING_HINT_003_PC");
      else
        UFG::qString::Format(&v21, "$UNLOCKABLE_LOADING_HINT_%03d", v19);
    }
    else
    {
      UFG::qString::Format(&v21, "NO GENERIC HINTS TO DISPLAY", 0i64);
    }
  }
  `eh vector constructor iterator'(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v20 = v21.mData;
  if ( (v25 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v24 + 16i64))(v24, &ptr, v26);
    v24 = 0i64;
  }
  v25 = 6;
  v26 = v20;
  Scaleform::GFx::Movie::Invoke(v2, "Set_Text", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
  `eh vector destructor iterator'(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  UFG::qString::~qString(&v21);
}

