// File Line: 101
// RVA: 0x221140
void __fastcall UFG::MovieResourceDataInventory::Add(UFG::MovieResourceDataInventory *this, UFG::qResourceData *data)
{
  UFG::qResourceData *v2; // rbx
  UFG::MovieResourceDataInventory *v3; // r14
  UFG::MoviePlayer *v4; // rdi
  UFG::MovieResourceData *v5; // rsi
  UFG::allocator::free_link *v6; // rax
  UFG::MoviePlayer *v7; // rax

  v2 = data;
  v3 = this;
  v4 = 0i64;
  if ( data )
  {
    UFG::qResourceData::qResourceData(data);
    v5 = (UFG::MovieResourceData *)v2;
  }
  else
  {
    v5 = 0i64;
  }
  if ( v3->vfptr->Get((UFG::qResourceInventory *)&v3->vfptr, v5->mNode.mUID) )
  {
    v5->mPlayer = 0i64;
  }
  else
  {
    v6 = UFG::qMalloc(0x58ui64, "MovieResourceDataInventory::MoviePlayer", 0i64);
    if ( v6 )
    {
      UFG::MoviePlayer::MoviePlayer((UFG::MoviePlayer *)v6);
      v4 = v7;
    }
    v5->mPlayer = v4;
    UFG::MoviePlayer::InitInMemory(v4, v5, 4u);
  }
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, v2);
}

// File Line: 124
// RVA: 0x222330
void __fastcall UFG::MovieResourceDataInventory::Remove(UFG::MovieResourceDataInventory *this, UFG::qResourceData *data)
{
  UFG::qResourceData *v2; // rdi
  UFG::MovieResourceDataInventory *v3; // rsi
  UFG::MoviePlayer *v4; // rcx
  UFG::MoviePlayer *v5; // rbx
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v6; // rdx
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v7; // rax
  UFG::MovieResourceData *v8; // rbx
  UFG::allocator::free_link *v9; // rax

  v2 = data;
  v3 = this;
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, data);
  v4 = (UFG::MoviePlayer *)v2[1].mNode.mParent;
  if ( v4 )
  {
    UFG::MoviePlayer::Close(v4);
    v5 = (UFG::MoviePlayer *)v2[1].mNode.mParent;
    if ( v5 )
    {
      UFG::MoviePlayer::Close(v5);
      UFG::qResourceHandle::~qResourceHandle(&v5->mTargetTexture);
      v6 = v5->mPrev;
      v7 = v5->mNext;
      v6->mNext = v7;
      v7->mPrev = v6;
      v5->mPrev = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)&v5->mPrev;
      v5->mNext = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)&v5->mPrev;
      operator delete[](v5);
    }
    v8 = (UFG::MovieResourceData *)v3->vfptr->Get((UFG::qResourceInventory *)&v3->vfptr, v2->mNode.mUID);
    if ( v8 )
    {
      v9 = UFG::qMalloc(0x58ui64, "MovieResourceDataInventory::MoviePlayer", 0i64);
      if ( v9 )
        UFG::MoviePlayer::MoviePlayer((UFG::MoviePlayer *)v9);
      v8->mPlayer = (UFG::MoviePlayer *)v9;
      UFG::MoviePlayer::InitInMemory((UFG::MoviePlayer *)v9, v8, 4u);
    }
  }
}

// File Line: 145
// RVA: 0x146F100
__int64 UFG::_dynamic_initializer_for__gMovieResourceDataInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&gMovieResourceDataInventory.vfptr,
    "MovieResourceDataInventory",
    0x399051EFu,
    0xE9453F67,
    0,
    0);
  gMovieResourceDataInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::MovieResourceDataInventory::`vftable';
  return atexit(UFG::_dynamic_atexit_destructor_for__gMovieResourceDataInventory__);
}

// File Line: 147
// RVA: 0x146F090
__int64 UFG::_dynamic_initializer_for__TheMovieHandler__()
{
  stru_142042A70.mNode.mPrev = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)&stru_142042A70;
  stru_142042A70.mNode.mNext = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)&stru_142042A70;
  UFG::qMutex::qMutex((UFG::qMutex *)&stru_142042A80, &customWorldMapCaption);
  dword_142042AB0[0] = 0;
  return atexit(UFG::_dynamic_atexit_destructor_for__TheMovieHandler__);
}

// File Line: 177
// RVA: 0x221050
void __fastcall UFG::MoviePlayer::MoviePlayer(UFG::MoviePlayer *this)
{
  UFG::MoviePlayer *v1; // rbx

  v1 = this;
  this->mPrev = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)&this->mPrev;
  this->mTarget = 0i64;
  UFG::qResourceHandle::qResourceHandle(&this->mTargetTexture);
  v1->mFlags = 0;
  v1->mFilename = 0i64;
  v1->mMovieData = 0i64;
  *(_WORD *)&v1->mIsPaused = 0;
  v1->mRenderOverUI = 0;
  ++UFG::MoviePlayer::mMovieIndex;
}

// File Line: 182
// RVA: 0x2210F0
void __fastcall UFG::MoviePlayer::~MoviePlayer(UFG::MoviePlayer *this)
{
  UFG::MoviePlayer *v1; // rbx
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v2; // rdx
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v3; // rax

  v1 = this;
  UFG::MoviePlayer::Close(this);
  UFG::qResourceHandle::~qResourceHandle(&v1->mTargetTexture);
  v2 = v1->mPrev;
  v3 = v1->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mPrev = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)&v1->mPrev;
}

// File Line: 187
// RVA: 0x221510
signed __int64 __fastcall UFG::MoviePlayer::Init(UFG::MoviePlayer *this, const char *fname, Illusion::Target *target, unsigned int flags)
{
  unsigned int v4; // ebp
  Illusion::Target *v5; // r14
  const char *v6; // rsi
  UFG::MoviePlayer *v7; // rbx
  UFG::allocator::free_link *v8; // rax
  UFG::allocator::free_link *v9; // rdi
  int v10; // edx
  hkGeometryUtils::IVertices *v11; // rcx
  int v12; // er8
  const char *v13; // rdi
  IDirectSound8 *v14; // rax
  signed __int64 v15; // rdx
  UFG::MovieData *v16; // rdx
  BINK *v17; // rcx
  __int64 v18; // rax
  signed __int64 v19; // rax
  unsigned int v20; // edi
  __int64 v21; // r14
  __int64 v22; // rsi
  UFG::qString *v23; // rax
  UFG::qString *v24; // rax
  UFG::qString *v25; // rax
  int v26; // esi
  __int64 v27; // rdi
  unsigned int v28; // ebp
  UFG::qResourceHandle *v29; // rdi
  UFG::qResourceInventory *v30; // rax
  UFG::qResourceWarehouse *v31; // rax
  Illusion::Material *v32; // rsi
  int v33; // edi
  UFG::qResourceWarehouse *v34; // rax
  UFG::qResourceHandle *v35; // rdi
  UFG::qResourceInventory *v36; // rax
  UFG::qResourceWarehouse *v37; // rax
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v38; // rdx
  UFG::qString result; // [rsp+48h] [rbp-A0h]
  UFG::qString v40; // [rsp+70h] [rbp-78h]
  UFG::qString v41; // [rsp+98h] [rbp-50h]

  v4 = flags;
  v5 = target;
  v6 = fname;
  v7 = this;
  UFG::qPrintf("Initialize full-screen Bink movie '%s'\n");
  v8 = UFG::qMalloc(0x140ui64, "MovieData", 0i64);
  v9 = v8;
  if ( v8 )
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v8[8]);
  else
    v9 = 0i64;
  v7->mMovieData = (UFG::MovieData *)v9;
  v7->mFilename = v6;
  v7->mFlags = v4;
  v7->mTarget = v5;
  UFG::qTaskManager::Sync(&UFG::gTaskManager);
  Illusion::IEnginePlat::WaitUntilGPUDone((Illusion::IEnginePlat *)&Illusion::gEngine);
  v13 = v7->mFilename;
  if ( !UFG::gBinkAudioInited && Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v11, v10, v12) )
  {
    v14 = AK::GetDirectSoundInstance();
    BinkSetSoundSystem(BinkOpenDirectSound, v14);
  }
  v15 = 1024i64;
  if ( v7->mFlags & 0x40 )
    v15 = 17408i64;
  v7->mMovieData->mBinkHandle = (BINK *)BinkOpen(v13, v15);
  v16 = v7->mMovieData;
  v17 = v16->mBinkHandle;
  if ( v17 )
  {
    BinkGetFrameBuffersInfo(v17, &v16->mBinkFrameBuffers);
    v20 = 0;
    if ( v7->mMovieData->mBinkFrameBuffers.TotalFrames > 0 )
    {
      v21 = 0i64;
      v22 = 0i64;
      do
      {
        if ( v7->mMovieData->mBinkFrameBuffers.Frames[v22].YPlane.Allocate )
        {
          v23 = UFG::qString::FormatEx(&result, "Bink_texY_%d_%d", v20, UFG::MoviePlayer::mMovieIndex);
          v7->mMovieData->mBuffer[v21].mTextureY = (Illusion::Texture *)Illusion::CreateTexture(
                                                                          v23->mData,
                                                                          v7->mMovieData->mBinkFrameBuffers.YABufferWidth,
                                                                          v7->mMovieData->mBinkFrameBuffers.YABufferHeight,
                                                                          FORMAT_X8,
                                                                          0x440500u,
                                                                          1,
                                                                          0,
                                                                          0);
          UFG::qString::~qString(&result);
        }
        if ( v7->mMovieData->mBinkFrameBuffers.Frames[v22].cRPlane.Allocate )
        {
          v24 = UFG::qString::FormatEx(&v40, "Bink_texR_%d_%d", v20, UFG::MoviePlayer::mMovieIndex);
          v7->mMovieData->mBuffer[v21].mTextureR = (Illusion::Texture *)Illusion::CreateTexture(
                                                                          v24->mData,
                                                                          v7->mMovieData->mBinkFrameBuffers.cRcBBufferWidth,
                                                                          v7->mMovieData->mBinkFrameBuffers.cRcBBufferHeight,
                                                                          FORMAT_X8,
                                                                          0x440500u,
                                                                          1,
                                                                          0,
                                                                          0);
          UFG::qString::~qString(&v40);
        }
        if ( v7->mMovieData->mBinkFrameBuffers.Frames[v22].cBPlane.Allocate )
        {
          v25 = UFG::qString::FormatEx(&v41, "Bink_texB_%d_%d", v20, UFG::MoviePlayer::mMovieIndex);
          v7->mMovieData->mBuffer[v21].mTextureB = (Illusion::Texture *)Illusion::CreateTexture(
                                                                          v25->mData,
                                                                          v7->mMovieData->mBinkFrameBuffers.cRcBBufferWidth,
                                                                          v7->mMovieData->mBinkFrameBuffers.cRcBBufferHeight,
                                                                          FORMAT_X8,
                                                                          0x440500u,
                                                                          1,
                                                                          0,
                                                                          0);
          UFG::qString::~qString(&v41);
        }
        ++v20;
        ++v22;
        ++v21;
      }
      while ( (signed int)v20 < v7->mMovieData->mBinkFrameBuffers.TotalFrames );
    }
    UFG::MoviePlayer::LockTextures(v7);
    v26 = 0;
    if ( v7->mMovieData->mBinkFrameBuffers.TotalFrames > 0 )
    {
      v27 = 0i64;
      do
      {
        Illusion::ITexturePlat::Unlock((Illusion::ITexturePlat *)v7->mMovieData->mBuffer[v27].mTextureY);
        Illusion::ITexturePlat::Unlock((Illusion::ITexturePlat *)v7->mMovieData->mBuffer[v27].mTextureR);
        Illusion::ITexturePlat::Unlock((Illusion::ITexturePlat *)v7->mMovieData->mBuffer[v27].mTextureB);
        ++v26;
        ++v27;
      }
      while ( v26 < v7->mMovieData->mBinkFrameBuffers.TotalFrames );
    }
    v28 = UFG::qStringHashUpper32("MovieNoAlpha", 0xFFFFFFFF);
    v29 = (UFG::qResourceHandle *)v7->mMovieData;
    v30 = `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Material>'::`2'::result )
    {
      v31 = UFG::qResourceWarehouse::Instance();
      v30 = UFG::qResourceWarehouse::GetInventory(v31, 0xB4C26312);
      `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result = v30;
    }
    UFG::qResourceHandle::Init(v29 + 2, 0xB4C26312, v28, v30);
    if ( !v7->mMovieData->mMaterial.mData )
    {
      v32 = Illusion::Factory::NewMaterial("MovieNoAlpha", v28, 6u, 0i64, 0i64, 0i64);
      v33 = UFG::qStringHash32("MOVIEPLAYER", 0xFFFFFFFF);
      LOWORD(v32[1].mNode.mChild[0]) = 0;
      HIDWORD(v32[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
      LODWORD(v32[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
      v32[1].mTypeUID = -1957338719;
      LODWORD(v32[1].mResourceHandles.mNode.mNext) = v33;
      *(_WORD *)&v32[1].mDebugName[12] = 0;
      *(_DWORD *)&v32[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
      *(_DWORD *)&v32[1].mDebugName[4] = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
      LODWORD(v32[1].mStateBlockMask.mFlags[1]) = -1958479169;
      LODWORD(v32[1].mStateBlockMask.mFlags[0]) = 0;
      LOWORD(v32[1].mMaterialUser.mOffset) = 0;
      *(&v32[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
      v32[1].mNumParams = UFG::qStringHash32("texDiffuse2", 0xFFFFFFFF);
      LODWORD(v32[2].mResourceHandles.mNode.mPrev) = -1958479169;
      v32[2].mNode.mUID = 0;
      LOWORD(v32[2].mTypeUID) = 0;
      HIDWORD(v32[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
      LODWORD(v32[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("texDiffuseWorld", 0xFFFFFFFF);
      *((_DWORD *)&v32[2].0 + 22) = -1958479169;
      *(_DWORD *)&v32[2].mDebugName[28] = 0;
      LOWORD(v32[2].mStateBlockMask.mFlags[1]) = 0;
      HIDWORD(v32[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
      LODWORD(v32[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
      LODWORD(v32[3].mNode.mChild[1]) = 315097330;
      LODWORD(v32[3].mNode.mChild[0]) = 662883558;
      LOWORD(v32[3].mResourceHandles.mNode.mPrev) = 0;
      *(&v32[3].mNode.mUID + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
      v32[3].mNode.mUID = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
      *(_DWORD *)&v32[3].mDebugName[20] = 1002903008;
      *(_DWORD *)&v32[3].mDebugName[12] = 1660426324;
      v34 = UFG::qResourceWarehouse::Instance();
      UFG::qResourceWarehouse::Add(v34, (UFG::qResourceData *)&v32->mNode);
      v35 = (UFG::qResourceHandle *)v7->mMovieData;
      v36 = `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Material>'::`2'::result )
      {
        v37 = UFG::qResourceWarehouse::Instance();
        v36 = UFG::qResourceWarehouse::GetInventory(v37, 0xB4C26312);
        `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result = v36;
      }
      UFG::qResourceHandle::Init(v35 + 2, 0xB4C26312, v28, v36);
    }
    UFG::qMutex::Lock(&stru_142042A80);
    v38 = UFG::TheMovieHandler.mActiveMovies.mNode.mPrev;
    UFG::TheMovieHandler.mActiveMovies.mNode.mPrev->mNext = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)&v7->mPrev;
    v7->mPrev = v38;
    v7->mNext = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)&UFG::TheMovieHandler;
    UFG::TheMovieHandler.mActiveMovies.mNode.mPrev = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)&v7->mPrev;
    v7->mbFirstFrame = 1;
    UFG::qMutex::Unlock(&stru_142042A80);
    v19 = 1i64;
  }
  else
  {
    v7->mFlags |= 1u;
    v18 = BinkGetError();
    UFG::qPrintf("Bink error: %s\n", v18);
    v19 = 0i64;
  }
  return v19;
}

// File Line: 379
// RVA: 0x221B00
signed __int64 __fastcall UFG::MoviePlayer::InitInMemory(UFG::MoviePlayer *this, UFG::MovieResourceData *data, unsigned int flags)
{
  UFG::MovieResourceData *v3; // r14
  UFG::MoviePlayer *v4; // rbx
  UFG::allocator::free_link *v5; // rax
  UFG::allocator::free_link *v6; // rdi
  __int64 v7; // rax
  signed __int64 result; // rax
  UFG::qResourceWarehouse *v9; // rax
  UFG::qResourceInventory *v10; // rdi
  int v11; // ebp
  __int64 v12; // rsi
  unsigned int *v13; // r14
  int v14; // esi
  __int64 v15; // rdi
  unsigned int v16; // ebp
  UFG::qResourceHandle *v17; // rdi
  UFG::qResourceInventory *v18; // rax
  UFG::qResourceWarehouse *v19; // rax
  Illusion::Material *v20; // rsi
  int v21; // edi
  UFG::qResourceWarehouse *v22; // rax
  UFG::qResourceHandle *v23; // rdi
  UFG::qResourceInventory *v24; // rax
  UFG::qResourceWarehouse *v25; // rax
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v26; // rax

  v3 = data;
  v4 = this;
  this->mFlags = flags | 0x10;
  UFG::qResourceHandle::Init(&this->mTargetTexture, 0x8B43FABF, data->mTargetTextureUID);
  v4->mFilename = v3->mDebugName;
  BinkSetIOSize(0i64);
  v5 = UFG::qMalloc(0x140ui64, "MovieData", 0i64);
  v6 = v5;
  if ( v5 )
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v5[8]);
  else
    v6 = 0i64;
  v4->mMovieData = (UFG::MovieData *)v6;
  v4->mMovieData->mBinkHandle = (BINK *)BinkOpen(&v3[1], 85984256i64);
  if ( v4->mMovieData->mBinkHandle )
  {
    v9 = UFG::qResourceWarehouse::Instance();
    v10 = UFG::qResourceWarehouse::GetInventory(v9, 0x8B43FABF);
    BinkGetFrameBuffersInfo(v4->mMovieData->mBinkHandle, &v4->mMovieData->mBinkFrameBuffers);
    v11 = 0;
    if ( v4->mMovieData->mBinkFrameBuffers.TotalFrames > 0 )
    {
      v12 = 0i64;
      v13 = &v3->mBuffers[0].mRTextureUID;
      do
      {
        v4->mMovieData->mBuffer[v12].mTextureY = (Illusion::Texture *)v10->vfptr->Get(v10, *(v13 - 1));
        v4->mMovieData->mBuffer[v12].mTextureR = (Illusion::Texture *)v10->vfptr->Get(v10, *v13);
        v4->mMovieData->mBuffer[v12].mTextureB = (Illusion::Texture *)v10->vfptr->Get(v10, v13[1]);
        ++v11;
        v13 += 3;
        ++v12;
      }
      while ( v11 < v4->mMovieData->mBinkFrameBuffers.TotalFrames );
    }
    UFG::MoviePlayer::LockTextures(v4);
    v14 = 0;
    if ( v4->mMovieData->mBinkFrameBuffers.TotalFrames > 0 )
    {
      v15 = 0i64;
      do
      {
        Illusion::ITexturePlat::Unlock((Illusion::ITexturePlat *)v4->mMovieData->mBuffer[v15].mTextureY);
        Illusion::ITexturePlat::Unlock((Illusion::ITexturePlat *)v4->mMovieData->mBuffer[v15].mTextureR);
        Illusion::ITexturePlat::Unlock((Illusion::ITexturePlat *)v4->mMovieData->mBuffer[v15].mTextureB);
        ++v14;
        ++v15;
      }
      while ( v14 < v4->mMovieData->mBinkFrameBuffers.TotalFrames );
    }
    v16 = UFG::qStringHashUpper32("MovieNoAlpha", 0xFFFFFFFF);
    v17 = (UFG::qResourceHandle *)v4->mMovieData;
    v18 = `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Material>'::`2'::result )
    {
      v19 = UFG::qResourceWarehouse::Instance();
      v18 = UFG::qResourceWarehouse::GetInventory(v19, 0xB4C26312);
      `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result = v18;
    }
    UFG::qResourceHandle::Init(v17 + 2, 0xB4C26312, v16, v18);
    if ( !v4->mMovieData->mMaterial.mData )
    {
      v20 = Illusion::Factory::NewMaterial("MovieNoAlpha", v16, 6u, 0i64, 0i64, 0i64);
      v21 = UFG::qStringHash32("MOVIEPLAYER", 0xFFFFFFFF);
      LOWORD(v20[1].mNode.mChild[0]) = 0;
      HIDWORD(v20[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
      LODWORD(v20[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
      v20[1].mTypeUID = -1957338719;
      LODWORD(v20[1].mResourceHandles.mNode.mNext) = v21;
      *(_WORD *)&v20[1].mDebugName[12] = 0;
      *(_DWORD *)&v20[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
      *(_DWORD *)&v20[1].mDebugName[4] = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
      LODWORD(v20[1].mStateBlockMask.mFlags[1]) = -1958479169;
      LODWORD(v20[1].mStateBlockMask.mFlags[0]) = 0;
      LOWORD(v20[1].mMaterialUser.mOffset) = 0;
      *(&v20[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
      v20[1].mNumParams = UFG::qStringHash32("texDiffuse2", 0xFFFFFFFF);
      LODWORD(v20[2].mResourceHandles.mNode.mPrev) = -1958479169;
      v20[2].mNode.mUID = 0;
      LOWORD(v20[2].mTypeUID) = 0;
      HIDWORD(v20[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
      LODWORD(v20[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("texDiffuseWorld", 0xFFFFFFFF);
      *((_DWORD *)&v20[2].0 + 22) = -1958479169;
      *(_DWORD *)&v20[2].mDebugName[28] = 0;
      LOWORD(v20[2].mStateBlockMask.mFlags[1]) = 0;
      HIDWORD(v20[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
      LODWORD(v20[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
      LODWORD(v20[3].mNode.mChild[1]) = 315097330;
      LODWORD(v20[3].mNode.mChild[0]) = 662883558;
      LOWORD(v20[3].mResourceHandles.mNode.mPrev) = 0;
      *(&v20[3].mNode.mUID + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
      v20[3].mNode.mUID = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
      *(_DWORD *)&v20[3].mDebugName[20] = 1002903008;
      *(_DWORD *)&v20[3].mDebugName[12] = 1660426324;
      v22 = UFG::qResourceWarehouse::Instance();
      UFG::qResourceWarehouse::Add(v22, (UFG::qResourceData *)&v20->mNode);
      v23 = (UFG::qResourceHandle *)v4->mMovieData;
      v24 = `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Material>'::`2'::result )
      {
        v25 = UFG::qResourceWarehouse::Instance();
        v24 = UFG::qResourceWarehouse::GetInventory(v25, 0xB4C26312);
        `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result = v24;
      }
      UFG::qResourceHandle::Init(v23 + 2, 0xB4C26312, v16, v24);
    }
    UFG::qMutex::Lock(&stru_142042A80);
    v26 = UFG::TheMovieHandler.mActiveMovies.mNode.mPrev;
    UFG::TheMovieHandler.mActiveMovies.mNode.mPrev->mNext = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)&v4->mPrev;
    v4->mPrev = v26;
    v4->mNext = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)&UFG::TheMovieHandler;
    UFG::TheMovieHandler.mActiveMovies.mNode.mPrev = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)&v4->mPrev;
    UFG::qMutex::Unlock(&stru_142042A80);
    result = 1i64;
  }
  else
  {
    v4->mFlags |= 1u;
    v7 = BinkGetError();
    UFG::qPrintf("Bink error: %s\n", v7);
    result = 0i64;
  }
  return result;
}

// File Line: 465
// RVA: 0x222410
__int64 __fastcall UFG::MoviePlayer::Render(UFG::MoviePlayer *this, Render::View *view)
{
  Render::View *v2; // rbp
  UFG::MoviePlayer *v3; // rbx
  unsigned int v4; // eax
  Illusion::Texture *v5; // rdi
  Illusion::Target *v6; // rdx
  _WORD *v7; // rdi
  UFG::MovieData *v8; // rdx
  UFG::MovieData::Buffer *v9; // r14
  unsigned int v10; // er8
  UFG::qResourceData *v11; // rsi
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v12; // rax
  _WORD *v13; // rax
  unsigned int v14; // er8
  UFG::qResourceData *v15; // rsi
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v16; // rax
  _WORD *v17; // rax
  unsigned int v18; // er8
  UFG::qResourceData *v19; // rsi
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v20; // rax
  Illusion::CreateTargetParams params; // [rsp+60h] [rbp-C8h]
  Render::Poly poly; // [rsp+130h] [rbp+8h]

  v2 = view;
  v3 = this;
  v4 = this->mFlags;
  if ( !(v4 & 1) || v4 & 4 )
  {
    if ( v4 & 0x10 && !this->mTarget )
    {
      v5 = (Illusion::Texture *)this->mTargetTexture.mData;
      if ( !v5 || UFG::qResourceHandle::IsDefault(&this->mTargetTexture) )
        return 0i64;
      Illusion::CreateTargetParams::CreateTargetParams(&params, v5->mDebugName, 0);
      params.textures[0] = v5;
      v3->mTarget = Illusion::CreateTarget(&params);
      UFG::qString::~qString(&params.name);
    }
    v6 = v3->mTarget;
    v7 = 0i64;
    if ( v6 )
      Render::View::BeginTarget(v2, v6, "Movie", 0, 0, 0i64, 1, 0, 0, 0);
    v8 = v3->mMovieData;
    v9 = &v8->mBuffer[v8->mBinkHandle->FrameBuffers->FrameNum == 0];
    v10 = v9->mTextureY->mNode.mUID;
    v11 = v8->mMaterial.mData;
    if ( v11[2].mTypeUID != v10 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v11[2].mNode.mUID, *(_DWORD *)&v11[2].mDebugName[4], v10);
      v12 = v11[1].mResourceHandles.mNode.mPrev;
      if ( v12 )
        v13 = (_WORD *)((char *)&v12[7].mNext + (_QWORD)v11);
      else
        v13 = 0i64;
      *v13 |= 0x20u;
    }
    v14 = v9->mTextureR->mNode.mUID;
    v15 = v3->mMovieData->mMaterial.mData;
    if ( LODWORD(v15[3].mNode.mChild[1]) != v14 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v15[2].mDebugName[28], v15[3].mNode.mUID, v14);
      v16 = v15[1].mResourceHandles.mNode.mPrev;
      if ( v16 )
        v17 = (_WORD *)((char *)&v16[7].mNext + (_QWORD)v15);
      else
        v17 = 0i64;
      *v17 |= 0x20u;
    }
    v18 = v9->mTextureB->mNode.mUID;
    v19 = v3->mMovieData->mMaterial.mData;
    if ( *(_DWORD *)&v19[3].mDebugName[20] != v18 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v19[3].mTypeUID, *(_DWORD *)&v19[3].mDebugName[28], v18);
      v20 = v19[1].mResourceHandles.mNode.mPrev;
      if ( v20 )
        v7 = (_WORD *)((char *)&v19[1].mResourceHandles + (_QWORD)v20);
      *v7 |= 0x20u;
    }
    if ( !v3->mbFirstFrame || v3->mFlags & 0x10 || v3->mMovieData->mBinkHandle->FrameNum >= 3 )
    {
      v3->mbFirstFrame = 0;
      Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
      Render::View::Draw(v2, &poly, (Illusion::Material *)v3->mMovieData->mMaterial.mData, 0i64);
    }
    else
    {
      Render::View::Clear(v2, &UFG::qColour::Black, 1u, 1.0, 1u);
    }
    if ( v3->mTarget )
      Render::View::EndTarget(v2);
  }
  return 0i64;
}

// File Line: 543
// RVA: 0x222000
void __fastcall UFG::MoviePlayer::LockTextures(UFG::MoviePlayer *this)
{
  UFG::MovieData *v1; // rax
  UFG::MoviePlayer *v2; // rbx
  unsigned int v3; // er15
  int v4; // ebp
  __int64 v5; // rdi
  __int64 v6; // rsi
  Illusion::ITexturePlat::LockType v7; // er14
  Illusion::TextureLockInfo info; // [rsp+30h] [rbp-38h]

  v1 = this->mMovieData;
  v2 = this;
  v3 = v1->mBinkFrameBuffers.FrameNum;
  v4 = 0;
  if ( v1->mBinkFrameBuffers.TotalFrames > 0 )
  {
    v5 = 0i64;
    v6 = 0i64;
    do
    {
      v7 = 3;
      if ( v4 != v3 )
        v7 = 1;
      if ( Illusion::ITexturePlat::Lock((Illusion::ITexturePlat *)v1->mBuffer[v6].mTextureY, v7, &info, 0, 0) )
      {
        v2->mMovieData->mBinkFrameBuffers.Frames[v5].YPlane.Buffer = info.mData;
        v2->mMovieData->mBinkFrameBuffers.Frames[v5].YPlane.BufferPitch = info.mLinePitch;
      }
      if ( Illusion::ITexturePlat::Lock(
             (Illusion::ITexturePlat *)v2->mMovieData->mBuffer[v6].mTextureR,
             v7,
             &info,
             0,
             0) )
      {
        v2->mMovieData->mBinkFrameBuffers.Frames[v5].cRPlane.Buffer = info.mData;
        v2->mMovieData->mBinkFrameBuffers.Frames[v5].cRPlane.BufferPitch = info.mLinePitch;
      }
      if ( Illusion::ITexturePlat::Lock(
             (Illusion::ITexturePlat *)v2->mMovieData->mBuffer[v6].mTextureB,
             v7,
             &info,
             0,
             0) )
      {
        v2->mMovieData->mBinkFrameBuffers.Frames[v5].cBPlane.Buffer = info.mData;
        v2->mMovieData->mBinkFrameBuffers.Frames[v5].cBPlane.BufferPitch = info.mLinePitch;
      }
      v1 = v2->mMovieData;
      ++v4;
      ++v6;
      ++v5;
    }
    while ( v4 < v1->mBinkFrameBuffers.TotalFrames );
  }
  BinkRegisterFrameBuffers(v2->mMovieData->mBinkHandle, &v2->mMovieData->mBinkFrameBuffers);
}

// File Line: 575
// RVA: 0x222BD0
void __fastcall UFG::MoviePlayer::UnlockTextures(UFG::MoviePlayer *this)
{
  UFG::MovieData *v1; // rax
  int v2; // edi
  UFG::MoviePlayer *v3; // rsi
  __int64 v4; // rbx

  v1 = this->mMovieData;
  v2 = 0;
  v3 = this;
  if ( v1->mBinkFrameBuffers.TotalFrames > 0 )
  {
    v4 = 0i64;
    do
    {
      Illusion::ITexturePlat::Unlock((Illusion::ITexturePlat *)v1->mBuffer[v4].mTextureY);
      Illusion::ITexturePlat::Unlock((Illusion::ITexturePlat *)v3->mMovieData->mBuffer[v4].mTextureR);
      Illusion::ITexturePlat::Unlock((Illusion::ITexturePlat *)v3->mMovieData->mBuffer[v4].mTextureB);
      v1 = v3->mMovieData;
      ++v2;
      ++v4;
    }
    while ( v2 < v1->mBinkFrameBuffers.TotalFrames );
  }
}

// File Line: 590
// RVA: 0x222200
void __fastcall UFG::MoviePlayer::PlayFromStart(UFG::MoviePlayer *this, bool loop)
{
  bool v2; // di
  UFG::MoviePlayer *v3; // rbx
  bool v4; // zf
  UFG::MovieData *v5; // rcx

  v2 = loop;
  v3 = this;
  if ( this->mIsPaused )
  {
    v4 = (this->mFlags & 1) == 0;
    this->mIsPaused = 0;
    if ( v4 )
      BinkPause(this->mMovieData->mBinkHandle, 0i64);
  }
  if ( v2 )
    v3->mFlags |= 4u;
  else
    v3->mFlags &= 0xFFFFFFFB;
  v5 = v3->mMovieData;
  v3->mFlags &= 0xFFFFFFFE;
  BinkGoto(v5->mBinkHandle, 1i64);
}

// File Line: 630
// RVA: 0x222E80
signed __int64 __fastcall UFG::MoviePlayer::Update(UFG::MoviePlayer *this, bool inMovieLocation)
{
  unsigned int v2; // eax
  bool v3; // si
  UFG::MoviePlayer *v4; // rdi
  BINK *v6; // rbx

  v2 = this->mFlags;
  v3 = inMovieLocation;
  v4 = this;
  if ( v2 & 1 && !(v2 & 4) )
    return 0i64;
  if ( !this->mIsPaused )
  {
    v6 = this->mMovieData->mBinkHandle;
    UFG::MoviePlayer::LockTextures(this);
    if ( v3 || !(v4->mFlags & 0x10) )
    {
      BinkDoFrame(v6);
      if ( !(unsigned int)BinkWait(v6) )
      {
        while ( (unsigned int)BinkShouldSkip(v6) )
        {
          BinkNextFrame(v6);
          BinkDoFrame(v6);
          if ( v6->FrameNum == v6->Frames )
            v4->mFlags |= 1u;
        }
        BinkNextFrame(v6);
      }
    }
    if ( v6->FrameNum == v6->Frames )
      v4->mFlags |= 1u;
    UFG::MoviePlayer::UnlockTextures(v4);
  }
  return 1i64;
}

// File Line: 718
// RVA: 0x2211F0
void __fastcall UFG::MoviePlayer::Close(UFG::MoviePlayer *this)
{
  UFG::MoviePlayer *v1; // rbx
  UFG::MovieData *v2; // rax
  signed __int64 v3; // rcx
  int v4; // ebp
  __int64 v5; // rsi
  __int64 v6; // rdi
  UFG::MovieData *v7; // rcx
  UFG::MovieData *v8; // rcx
  UFG::MovieData *v9; // rcx
  UFG::qResourceHandle *v10; // rdi
  UFG::qResourceInventory *v11; // rax
  UFG::qResourceWarehouse *v12; // rax
  UFG::MovieHandler *v13; // rax
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v14; // rdx
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v15; // rax

  v1 = this;
  v2 = this->mMovieData;
  if ( v2 )
  {
    if ( this->mFlags & 0x10 )
    {
      if ( this->mTarget )
      {
        v3 = 2i64 * dword_142042AB0[0];
        ++dword_142042AB0[0];
        *((_QWORD *)unk_142042AB8 + v3) = v1->mTarget;
        *((_DWORD *)unk_142042AB8 + 2 * v3 + 2) = Illusion::gEngine.mFrameCount;
      }
    }
    else if ( v2->mBinkHandle )
    {
      Illusion::IEnginePlat::WaitUntilGPUDone((Illusion::IEnginePlat *)&Illusion::gEngine);
      v4 = 0;
      if ( v1->mMovieData->mBinkFrameBuffers.TotalFrames > 0 )
      {
        v5 = 0i64;
        v6 = 0i64;
        do
        {
          v7 = v1->mMovieData;
          if ( v7->mBinkFrameBuffers.Frames[v6].YPlane.Allocate )
            Illusion::DeleteTexture(v7->mBuffer[v5].mTextureY, 1);
          v8 = v1->mMovieData;
          if ( v8->mBinkFrameBuffers.Frames[v6].cRPlane.Allocate )
            Illusion::DeleteTexture(v8->mBuffer[v5].mTextureR, 1);
          v9 = v1->mMovieData;
          if ( v9->mBinkFrameBuffers.Frames[v6].cBPlane.Allocate )
            Illusion::DeleteTexture(v9->mBuffer[v5].mTextureB, 1);
          ++v4;
          ++v6;
          ++v5;
        }
        while ( v4 < v1->mMovieData->mBinkFrameBuffers.TotalFrames );
      }
    }
    BinkClose(v1->mMovieData->mBinkHandle);
    v10 = (UFG::qResourceHandle *)v1->mMovieData;
    if ( v10 )
    {
      v11 = `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Material>'::`2'::result )
      {
        v12 = UFG::qResourceWarehouse::Instance();
        v11 = UFG::qResourceWarehouse::GetInventory(v12, 0xB4C26312);
        `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result = v11;
      }
      UFG::qResourceHandle::Close(v10 + 2, v11);
      UFG::qResourceHandle::~qResourceHandle(v10 + 2);
      operator delete[](v10);
    }
    v1->mMovieData = 0i64;
    v1->mIsPaused = 0;
    UFG::qMutex::Lock(&stru_142042A80);
    v13 = (UFG::MovieHandler *)off_142042A68;
    if ( off_142042A68 != (UFG::MoviePlayer *)&UFG::TheMovieHandler )
    {
      while ( v13 != (UFG::MovieHandler *)v1 )
      {
        v13 = (UFG::MovieHandler *)v13->mActiveMovies.mNode.mNext;
        if ( v13 == &UFG::TheMovieHandler )
          goto LABEL_24;
      }
      v14 = v1->mPrev;
      v15 = v1->mNext;
      v14->mNext = v15;
      v15->mPrev = v14;
      v1->mPrev = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)&v1->mPrev;
      v1->mNext = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)&v1->mPrev;
    }
LABEL_24:
    UFG::qMutex::Unlock(&stru_142042A80);
  }
}

// File Line: 820
// RVA: 0x222970
void __fastcall UFG::MoviePlayer::SetAudioVolume(UFG::MoviePlayer *this, int track, int volume)
{
  unsigned int v3; // ebx
  unsigned int v4; // edi
  UFG::MoviePlayer *v5; // rsi

  v3 = volume;
  v4 = track;
  v5 = this;
  if ( UFG::TiDo::sm_isMuted )
    v3 = 0;
  if ( Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(
         (hkGeometryUtils::IVertices *)this,
         track,
         volume) )
  {
    BinkSetVolume(v5->mMovieData->mBinkHandle, v4, v3);
  }
}

// File Line: 834
// RVA: 0x221460
float __fastcall UFG::MovieHandler::GetNonInMemMovieLength(UFG::MovieHandler *this)
{
  UFG::MovieHandler *v1; // rbx
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v2; // rax
  float v3; // xmm6_4

  v1 = this;
  UFG::qMutex::Lock(&stru_142042A80);
  v2 = v1->mActiveMovies.mNode.mNext;
  if ( v2 == (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)v1 )
  {
LABEL_6:
    v3 = 0.0;
  }
  else
  {
    while ( (_QWORD)v2[3].mNext & 0x10 )
    {
      v2 = v2->mNext;
      if ( v2 == (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)v1 )
        goto LABEL_6;
    }
    v3 = (float)((float)((float)SHIDWORD(v2[4].mNext[6].mPrev[1].mPrev) / (float)SLODWORD(v2[4].mNext[6].mPrev[1].mNext))
               * (float)SLODWORD(v2[4].mNext[6].mPrev->mNext))
       * 0.001;
  }
  UFG::qMutex::Unlock(&stru_142042A80);
  return v3;
}

// File Line: 852
// RVA: 0x221F90
__int64 __fastcall UFG::MovieHandler::IsPlayingNonInMemMovies(UFG::MovieHandler *this)
{
  UFG::MovieHandler *v1; // rbx
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v2; // rax
  unsigned __int8 v3; // bl

  v1 = this;
  UFG::qMutex::Lock(&stru_142042A80);
  v2 = v1->mActiveMovies.mNode.mNext;
  if ( v2 == (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)v1 )
  {
LABEL_6:
    v3 = 0;
  }
  else
  {
    while ( (_QWORD)v2[3].mNext & 0x10 )
    {
      v2 = v2->mNext;
      if ( v2 == (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)v1 )
        goto LABEL_6;
    }
    v3 = 1;
  }
  UFG::qMutex::Unlock(&stru_142042A80);
  return v3;
}

// File Line: 868
// RVA: 0x222170
void __fastcall UFG::MovieHandler::Pause(UFG::MovieHandler *this)
{
  UFG::MovieHandler *v1; // rdi
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *i; // rbx

  v1 = this;
  UFG::qMutex::Lock(&stru_142042A80);
  for ( i = v1->mActiveMovies.mNode.mNext; i != (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)v1; i = i->mNext )
  {
    LOBYTE(i[5].mPrev) = 1;
    if ( !((_QWORD)i[3].mNext & 1) )
      BinkPause(i[4].mNext[6].mPrev, 1i64);
  }
  UFG::qMutex::Unlock(&stru_142042A80);
}

// File Line: 879
// RVA: 0x222C40
void __fastcall UFG::MovieHandler::Unpause(UFG::MovieHandler *this)
{
  UFG::MovieHandler *v1; // rdi
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *i; // rbx

  v1 = this;
  UFG::qMutex::Lock(&stru_142042A80);
  for ( i = v1->mActiveMovies.mNode.mNext; i != (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)v1; i = i->mNext )
  {
    LOBYTE(i[5].mPrev) = 0;
    if ( !((_QWORD)i[3].mNext & 1) )
      BinkPause(i[4].mNext[6].mPrev, 0i64);
  }
  UFG::qMutex::Unlock(&stru_142042A80);
}

// File Line: 890
// RVA: 0x2229C0
void __fastcall UFG::MovieHandler::SetVolumeAll(UFG::MovieHandler *this, int volume)
{
  int v2; // ebp
  UFG::MovieHandler *v3; // rsi
  int v4; // edx
  hkGeometryUtils::IVertices *v5; // rcx
  int v6; // er8
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *i; // rbx
  unsigned int v8; // edi

  v2 = volume;
  v3 = this;
  UFG::qMutex::Lock(&stru_142042A80);
  for ( i = v3->mActiveMovies.mNode.mNext; i != (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)v3; i = i->mNext )
  {
    v8 = v2;
    if ( UFG::TiDo::sm_isMuted )
      v8 = 0;
    if ( Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v5, v4, v6) )
      BinkSetVolume(i[4].mNext[6].mPrev, 0i64, v8);
  }
  UFG::qMutex::Unlock(&stru_142042A80);
}

// File Line: 916
// RVA: 0x222CC0
void __fastcall UFG::MovieHandler::Update(UFG::MovieHandler *this, bool inMovieLocation)
{
  bool v2; // si
  UFG::MovieHandler *v3; // rdi
  __int64 *v4; // rdx
  __int64 v5; // rcx
  __int64 *v6; // rax
  __int64 *v7; // rax
  UFG::MoviePlayer *i; // rbx
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v9; // rcx
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v10; // rax
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v11; // rax
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v12; // rax
  UFG::MoviePlayer *j; // rbx
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v14; // rcx
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v15; // rax
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v16; // rdx
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v17; // rax
  __int64 *v18; // rcx
  UFG::MoviePlayer *v19; // rax
  __int64 *v20; // [rsp+28h] [rbp-20h]
  UFG::MoviePlayer *v21; // [rsp+30h] [rbp-18h]

  v2 = inMovieLocation;
  v3 = this;
  v20 = (__int64 *)&v20;
  v21 = (UFG::MoviePlayer *)&v20;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mActiveMoviesMutex);
  for ( ; (UFG::MovieHandler *)v3->mActiveMovies.mNode.mNext != v3; v20 = v4 )
  {
    v4 = (__int64 *)v3->mActiveMovies.mNode.mNext;
    v5 = *v4;
    v6 = (__int64 *)v4[1];
    *(_QWORD *)(v5 + 8) = v6;
    *v6 = v5;
    *v4 = (__int64)v4;
    v4[1] = (__int64)v4;
    v7 = v20;
    v20[1] = (__int64)v4;
    *v4 = (__int64)v7;
    v4[1] = (__int64)&v20;
  }
  for ( i = v21; v21 != (UFG::MoviePlayer *)&v20; i = v21 )
  {
    v9 = i->mPrev;
    v10 = i->mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    i->mPrev = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)&i->mPrev;
    i->mNext = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)&i->mPrev;
    if ( UFG::MoviePlayer::Update(i, v2) )
    {
      v12 = v3->mActiveMovies.mNode.mPrev;
      v12->mNext = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)&i->mPrev;
      i->mPrev = v12;
      i->mNext = &v3->mActiveMovies.mNode;
      v3->mActiveMovies.mNode.mPrev = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)&i->mPrev;
    }
    else
    {
      v11 = v3->mFinishedMovies.mNode.mPrev;
      v11->mNext = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)&i->mPrev;
      i->mPrev = v11;
      i->mNext = &v3->mFinishedMovies.mNode;
      v3->mFinishedMovies.mNode.mPrev = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)&i->mPrev;
    }
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v3->mActiveMoviesMutex);
  for ( j = v21; v21 != (UFG::MoviePlayer *)&v20; j = v21 )
  {
    v14 = j->mPrev;
    v15 = j->mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    j->mPrev = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)&j->mPrev;
    j->mNext = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)&j->mPrev;
    UFG::MoviePlayer::Close(j);
    UFG::qResourceHandle::~qResourceHandle(&j->mTargetTexture);
    v16 = j->mPrev;
    v17 = j->mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    j->mPrev = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)&j->mPrev;
    j->mNext = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)&j->mPrev;
    operator delete[](j);
  }
  v18 = v20;
  v19 = v21;
  v20[1] = (__int64)v21;
  v19->mPrev = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)v18;
}

// File Line: 946
// RVA: 0x222270
void __fastcall UFG::MovieHandler::PostUpdate(UFG::MovieHandler *this)
{
  char **v1; // rbx
  UFG::MovieHandler *v2; // rsi
  UFG::MoviePlayer *v3; // rcx
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v4; // rdx
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v5; // rax
  unsigned int v6; // ebp
  __int64 v7; // rbx
  signed __int64 v8; // rdi
  signed __int64 v9; // rcx

  v1 = (char **)&this->mFinishedMovies;
  v2 = this;
  if ( (UFG::qList<UFG::MoviePlayer,UFG::MoviePlayer,1,0> *)this->mFinishedMovies.mNode.mNext != &this->mFinishedMovies )
  {
    do
    {
      v3 = (UFG::MoviePlayer *)v2->mFinishedMovies.mNode.mNext;
      v4 = v3->mPrev;
      v5 = v3->mNext;
      v4->mNext = v5;
      v5->mPrev = v4;
      v3->mPrev = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)&v3->mPrev;
      v3->mNext = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)&v3->mPrev;
      UFG::MoviePlayer::Close(v3);
    }
    while ( v1[1] != (char *)v1 );
  }
  v6 = Illusion::gEngine.mFrameCount;
  v7 = 0i64;
  if ( v2->mDoneTargets.size )
  {
    do
    {
      if ( v6 >= *((_DWORD *)&v2->mActiveMovies.mNode.mPrev + 4 * (v7 + 6)) + 3 )
      {
        v8 = (unsigned int)v7;
        Illusion::DeleteTarget(v2->mDoneTargets.p[(unsigned int)v7].mTarget, 0);
        v9 = --v2->mDoneTargets.size;
        LODWORD(v7) = v7 - 1;
        v2->mDoneTargets.p[v8].mTarget = v2->mDoneTargets.p[v2->mDoneTargets.size].mTarget;
        *(_QWORD *)&v2->mDoneTargets.p[v8].mMovieDeleteFrame = *(_QWORD *)&v2->mDoneTargets.p[v9].mMovieDeleteFrame;
      }
      v7 = (unsigned int)(v7 + 1);
    }
    while ( (unsigned int)v7 < v2->mDoneTargets.size );
  }
}

// File Line: 983
// RVA: 0x222A70
void __fastcall UFG::MovieHandler::ShouldAllowStreaming(UFG::MovieHandler *this, bool *game_streaming, bool *disk_caching)
{
  bool *v3; // rsi
  bool *v4; // r14
  UFG::MovieHandler *v5; // rdi
  unsigned int v6; // ebx
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *i; // rcx
  int v8; // eax
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *k; // rbx
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v10; // rcx
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *j; // rbx
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v12; // rcx
  char v13; // [rsp+28h] [rbp-50h]
  unsigned int v14; // [rsp+54h] [rbp-24h]
  int v15; // [rsp+58h] [rbp-20h]

  v3 = disk_caching;
  v4 = game_streaming;
  v5 = this;
  UFG::qMutex::Lock(&stru_142042A80);
  *v4 = 1;
  *v3 = 1;
  v6 = 100;
  for ( i = v5->mActiveMovies.mNode.mNext; i != (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)v5; i = i->mNext )
  {
    if ( !((_QWORD)i[3].mNext & 0x10) && i[4].mNext )
    {
      v8 = (int)i[3].mNext;
      if ( !(v8 & 1) || v8 & 4 )
        *v3 = 0;
      BinkGetRealtime(i[4].mNext[6].mPrev, &v13, 0i64);
      if ( v14 )
        v6 = 100 * v15 / v14;
      break;
    }
  }
  if ( UFG::gBinkStreamingMode )
  {
    if ( v6 < 0x1E )
    {
      UFG::gBinkStreamingMode = 0;
      for ( j = v5->mActiveMovies.mNode.mNext; j != (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)v5; j = j->mNext )
      {
        if ( !((_QWORD)j[3].mNext & 0x10) )
        {
          v12 = j[4].mNext;
          if ( v12 )
            BinkControlBackgroundIO(v12[6].mPrev, 2i64);
        }
      }
    }
  }
  else if ( v6 > 0x5A )
  {
    UFG::gBinkStreamingMode = 1;
    for ( k = v5->mActiveMovies.mNode.mNext; k != (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)v5; k = k->mNext )
    {
      if ( !((_QWORD)k[3].mNext & 0x10) )
      {
        v10 = k[4].mNext;
        if ( v10 )
          BinkControlBackgroundIO(v10[6].mPrev, 1i64);
      }
    }
  }
  *v4 = UFG::gBinkStreamingMode == 1;
  UFG::qMutex::Unlock(&stru_142042A80);
}

// File Line: 1058
// RVA: 0x222650
void __fastcall UFG::MovieHandler::RenderFullScreen(UFG::MovieHandler *this, Render::View *view, bool render_over_ui)
{
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v3; // rbx
  bool v4; // di
  Render::View *v5; // rsi
  UFG::MovieHandler *i; // rbp
  char v7; // al

  v3 = this->mActiveMovies.mNode.mNext;
  v4 = render_over_ui;
  v5 = view;
  for ( i = this; v3 != (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)i; v3 = v3->mNext )
  {
    if ( !((_QWORD)v3[3].mNext & 0x10) )
    {
      v7 = BYTE2(v3[5].mPrev);
      if ( !v7 )
        goto LABEL_11;
      if ( v4 )
        goto LABEL_7;
      if ( !v7 )
      {
LABEL_11:
        if ( !v4 )
        {
LABEL_7:
          UFG::MoviePlayer::Render((UFG::MoviePlayer *)v3, v5);
          continue;
        }
      }
    }
  }
}

// File Line: 1072
// RVA: 0x2226C0
void __fastcall UFG::MovieHandler::RenderOffScreen(UFG::MovieHandler *this, Illusion::SubmitContext *submit_context)
{
  Illusion::SubmitContext *v2; // r14
  UFG::MovieHandler *v3; // rbp
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v4; // rbx
  Render::ViewSettings *v5; // rax
  int v6; // eax
  Illusion::Texture *v7; // rdi
  Illusion::Target *v8; // rdx
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v9; // rdx
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v10; // rsi
  unsigned int v11; // er8
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v12; // rdi
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v13; // rax
  _WORD *v14; // rax
  unsigned int v15; // er8
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v16; // rdi
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v17; // rax
  _WORD *v18; // rax
  unsigned int v19; // er8
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v20; // rdi
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v21; // rax
  _WORD *v22; // rax
  Illusion::CreateTargetParams params; // [rsp+60h] [rbp-268h]
  Render::View v24; // [rsp+110h] [rbp-1B8h]
  Render::Poly poly; // [rsp+2D0h] [rbp+8h]

  v2 = submit_context;
  v3 = this;
  v4 = this->mActiveMovies.mNode.mNext;
  if ( v4 != (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)this )
  {
    while ( 1 )
    {
      v5 = Render::ViewSettings::GetIdentity();
      Render::View::View(&v24, v5, v2);
      v6 = (int)v4[3].mNext;
      if ( v6 & 0x10 )
      {
        if ( !(v6 & 1) || v6 & 4 )
        {
          if ( !(v6 & 0x10) || v4[1].mPrev )
            goto LABEL_10;
          v7 = (Illusion::Texture *)v4[2].mNext;
          if ( v7 )
          {
            if ( !UFG::qResourceHandle::IsDefault((UFG::qResourceHandle *)&v4[1].mNext) )
              break;
          }
        }
      }
LABEL_34:
      v4 = v4->mNext;
      if ( v4 == (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)v3 )
        return;
    }
    Illusion::CreateTargetParams::CreateTargetParams(&params, v7->mDebugName, 0);
    params.textures[0] = v7;
    v4[1].mPrev = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)Illusion::CreateTarget(&params);
    UFG::qString::~qString(&params.name);
LABEL_10:
    v8 = (Illusion::Target *)v4[1].mPrev;
    if ( v8 )
      Render::View::BeginTarget(&v24, v8, "Movie", 0, 0, 0i64, 1, 0, 0, 0);
    v9 = v4[4].mNext;
    v10 = &v9[2 * (HIDWORD(v9[6].mPrev[14].mPrev[1].mPrev) == 0)];
    v11 = (unsigned int)v10->mPrev[1].mNext;
    v12 = v9[5].mPrev;
    if ( LODWORD(v12[14].mPrev) != v11 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v12[12].mNext, (unsigned int)v12[14].mNext, v11);
      v13 = v12[7].mNext;
      if ( v13 )
        v14 = (_WORD *)((char *)&v13[7].mNext + (_QWORD)v12);
      else
        v14 = 0i64;
      *v14 |= 0x20u;
    }
    v15 = (unsigned int)v10->mNext[1].mNext;
    v16 = v4[4].mNext[5].mPrev;
    if ( LODWORD(v16[17].mNext) != v15 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v16[16], (unsigned int)v16[18].mPrev, v15);
      v17 = v16[7].mNext;
      if ( v17 )
        v18 = (_WORD *)((char *)&v17[7].mNext + (_QWORD)v16);
      else
        v18 = 0i64;
      *v18 |= 0x20u;
    }
    v19 = (unsigned int)v10[1].mPrev[1].mNext;
    v20 = v4[4].mNext[5].mPrev;
    if ( LODWORD(v20[21].mPrev) != v19 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v20[19].mNext, (unsigned int)v20[21].mNext, v19);
      v21 = v20[7].mNext;
      if ( v21 )
        v22 = (_WORD *)((char *)&v21[7].mNext + (_QWORD)v20);
      else
        v22 = 0i64;
      *v22 |= 0x20u;
    }
    if ( !BYTE1(v4[5].mPrev) || (_QWORD)v4[3].mNext & 0x10 || HIDWORD(v4[4].mNext[6].mPrev->mNext) >= 3 )
    {
      BYTE1(v4[5].mPrev) = 0;
      Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
      Render::View::Draw(&v24, &poly, (Illusion::Material *)v4[4].mNext[5].mPrev, 0i64);
    }
    else
    {
      Render::View::Clear(&v24, &UFG::qColour::Black, 1u, 1.0, 1u);
    }
    if ( v4[1].mPrev )
      Render::View::EndTarget(&v24);
    goto LABEL_34;
  }
}lack, 1u,

