// File Line: 101
// RVA: 0x221140
void __fastcall UFG::MovieResourceDataInventory::Add(
        UFG::MovieResourceDataInventory *this,
        UFG::MovieResourceData *data)
{
  UFG::MoviePlayer *v4; // rdi
  UFG::MovieResourceData *v5; // rsi
  UFG::allocator::free_link *v6; // rax
  UFG::MoviePlayer *v7; // rax

  v4 = 0i64;
  if ( data )
  {
    UFG::qResourceData::qResourceData(data);
    v5 = data;
  }
  else
  {
    v5 = 0i64;
  }
  if ( this->vfptr->Get(this, v5->mNode.mUID) )
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
  UFG::qResourceInventory::Add(this, data);
}

// File Line: 124
// RVA: 0x222330
void __fastcall UFG::MovieResourceDataInventory::Remove(
        UFG::MovieResourceDataInventory *this,
        UFG::qResourceData *data)
{
  UFG::qBaseNodeRB *mParent; // rcx
  UFG::MoviePlayer *v5; // rbx
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *mPrev; // rdx
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *mNext; // rax
  UFG::MovieResourceData *v8; // rbx
  UFG::allocator::free_link *v9; // rax

  UFG::qResourceInventory::Remove(this, data);
  mParent = data[1].mNode.mParent;
  if ( mParent )
  {
    UFG::MoviePlayer::Close((UFG::MoviePlayer *)mParent);
    v5 = (UFG::MoviePlayer *)data[1].mNode.mParent;
    if ( v5 )
    {
      UFG::MoviePlayer::Close(v5);
      UFG::qResourceHandle::~qResourceHandle(&v5->mTargetTexture);
      mPrev = v5->mPrev;
      mNext = v5->mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      v5->mPrev = v5;
      v5->mNext = v5;
      operator delete[](v5);
    }
    v8 = (UFG::MovieResourceData *)this->vfptr->Get(this, data->mNode.mUID);
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
    &gMovieResourceDataInventory,
    "MovieResourceDataInventory",
    0x399051EFu,
    0xE9453F67,
    0,
    0);
  gMovieResourceDataInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::MovieResourceDataInventory::`vftable;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gMovieResourceDataInventory__);
}

// File Line: 147
// RVA: 0x146F090
__int64 UFG::_dynamic_initializer_for__TheMovieHandler__()
{
  stru_142042A70.mNode.mPrev = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)&stru_142042A70;
  stru_142042A70.mNode.mNext = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)&stru_142042A70;
  UFG::qMutex::qMutex((UFG::qMutex *)&stru_142042A80, &customCaption);
  unk_142042AB0 = 0;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__TheMovieHandler__);
}

// File Line: 177
// RVA: 0x221050
void __fastcall UFG::MoviePlayer::MoviePlayer(UFG::MoviePlayer *this)
{
  this->mPrev = this;
  this->mNext = this;
  this->mTarget = 0i64;
  UFG::qResourceHandle::qResourceHandle(&this->mTargetTexture);
  this->mFlags = 0;
  this->mFilename = 0i64;
  this->mMovieData = 0i64;
  *(_WORD *)&this->mIsPaused = 0;
  this->mRenderOverUI = 0;
  ++UFG::MoviePlayer::mMovieIndex;
}

// File Line: 182
// RVA: 0x2210F0
void __fastcall UFG::MoviePlayer::~MoviePlayer(UFG::MoviePlayer *this)
{
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *mPrev; // rdx
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *mNext; // rax

  UFG::MoviePlayer::Close(this);
  UFG::qResourceHandle::~qResourceHandle(&this->mTargetTexture);
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 187
// RVA: 0x221510
signed __int64 __fastcall UFG::MoviePlayer::Init(
        UFG::MoviePlayer *this,
        const char *fname,
        Illusion::Target *target,
        unsigned int flags)
{
  UFG::allocator::free_link *v8; // rax
  UFG::MovieData *v9; // rdi
  int v10; // edx
  hkGeometryUtils::IVertices *v11; // rcx
  int v12; // r8d
  const char *mFilename; // rdi
  IDirectSound8 *DirectSoundInstance; // rax
  __int64 v15; // rdx
  UFG::MovieData *mMovieData; // rdx
  BINK *mBinkHandle; // rcx
  const char *Error; // rax
  unsigned int v20; // edi
  __int64 v21; // r14
  __int64 v22; // rsi
  UFG::qString *v23; // rax
  UFG::qString *v24; // rax
  UFG::qString *v25; // rax
  int v26; // esi
  __int64 v27; // rdi
  unsigned int v28; // ebp
  UFG::MovieData *v29; // rdi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v31; // rax
  Illusion::Material *v32; // rsi
  int v33; // edi
  UFG::qResourceWarehouse *v34; // rax
  UFG::MovieData *v35; // rdi
  UFG::qResourceInventory *v36; // rax
  UFG::qResourceWarehouse *v37; // rax
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *mPrev; // rdx
  UFG::qString result; // [rsp+48h] [rbp-A0h] BYREF
  UFG::qString v40; // [rsp+70h] [rbp-78h] BYREF
  UFG::qString v41; // [rsp+98h] [rbp-50h] BYREF

  UFG::qPrintf("Initialize full-screen Bink movie %s\n", fname);
  v8 = UFG::qMalloc(0x140ui64, "MovieData", 0i64);
  v9 = (UFG::MovieData *)v8;
  if ( v8 )
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v8[8]);
  else
    v9 = 0i64;
  this->mMovieData = v9;
  this->mFilename = fname;
  this->mFlags = flags;
  this->mTarget = target;
  UFG::qTaskManager::Sync(&UFG::gTaskManager);
  Illusion::IEnginePlat::WaitUntilGPUDone(&Illusion::gEngine);
  mFilename = this->mFilename;
  if ( !UFG::gBinkAudioInited && Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v11, v10, v12) )
  {
    DirectSoundInstance = AK::GetDirectSoundInstance();
    BinkSetSoundSystem(BinkOpenDirectSound, DirectSoundInstance);
  }
  v15 = 1024i64;
  if ( (this->mFlags & 0x40) != 0 )
    v15 = 17408i64;
  this->mMovieData->mBinkHandle = (BINK *)BinkOpen(mFilename, v15);
  mMovieData = this->mMovieData;
  mBinkHandle = mMovieData->mBinkHandle;
  if ( mBinkHandle )
  {
    BinkGetFrameBuffersInfo(mBinkHandle, &mMovieData->mBinkFrameBuffers);
    v20 = 0;
    if ( this->mMovieData->mBinkFrameBuffers.TotalFrames > 0 )
    {
      v21 = 0i64;
      v22 = 0i64;
      do
      {
        if ( this->mMovieData->mBinkFrameBuffers.Frames[v22].YPlane.Allocate )
        {
          v23 = UFG::qString::FormatEx(&result, "Bink_texY_%d_%d", v20, UFG::MoviePlayer::mMovieIndex);
          this->mMovieData->mBuffer[v21].mTextureY = (Illusion::Texture *)Illusion::CreateTexture(
                                                                            v23->mData,
                                                                            this->mMovieData->mBinkFrameBuffers.YABufferWidth,
                                                                            this->mMovieData->mBinkFrameBuffers.YABufferHeight,
                                                                            FORMAT_X8,
                                                                            0x440500u,
                                                                            1,
                                                                            0,
                                                                            0);
          UFG::qString::~qString(&result);
        }
        if ( this->mMovieData->mBinkFrameBuffers.Frames[v22].cRPlane.Allocate )
        {
          v24 = UFG::qString::FormatEx(&v40, "Bink_texR_%d_%d", v20, UFG::MoviePlayer::mMovieIndex);
          this->mMovieData->mBuffer[v21].mTextureR = (Illusion::Texture *)Illusion::CreateTexture(
                                                                            v24->mData,
                                                                            this->mMovieData->mBinkFrameBuffers.cRcBBufferWidth,
                                                                            this->mMovieData->mBinkFrameBuffers.cRcBBufferHeight,
                                                                            FORMAT_X8,
                                                                            0x440500u,
                                                                            1,
                                                                            0,
                                                                            0);
          UFG::qString::~qString(&v40);
        }
        if ( this->mMovieData->mBinkFrameBuffers.Frames[v22].cBPlane.Allocate )
        {
          v25 = UFG::qString::FormatEx(&v41, "Bink_texB_%d_%d", v20, UFG::MoviePlayer::mMovieIndex);
          this->mMovieData->mBuffer[v21].mTextureB = (Illusion::Texture *)Illusion::CreateTexture(
                                                                            v25->mData,
                                                                            this->mMovieData->mBinkFrameBuffers.cRcBBufferWidth,
                                                                            this->mMovieData->mBinkFrameBuffers.cRcBBufferHeight,
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
      while ( (signed int)v20 < this->mMovieData->mBinkFrameBuffers.TotalFrames );
    }
    UFG::MoviePlayer::LockTextures(this);
    v26 = 0;
    if ( this->mMovieData->mBinkFrameBuffers.TotalFrames > 0 )
    {
      v27 = 0i64;
      do
      {
        Illusion::ITexturePlat::Unlock(this->mMovieData->mBuffer[v27].mTextureY);
        Illusion::ITexturePlat::Unlock(this->mMovieData->mBuffer[v27].mTextureR);
        Illusion::ITexturePlat::Unlock(this->mMovieData->mBuffer[v27].mTextureB);
        ++v26;
        ++v27;
      }
      while ( v26 < this->mMovieData->mBinkFrameBuffers.TotalFrames );
    }
    v28 = UFG::qStringHashUpper32("MovieNoAlpha", -1);
    v29 = this->mMovieData;
    Inventory = `UFG::qGetResourceInventory<Illusion::Material>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Material>::`2::result )
    {
      v31 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v31, 0xB4C26312);
      `UFG::qGetResourceInventory<Illusion::Material>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&v29->mMaterial, 0xB4C26312, v28, Inventory);
    if ( !this->mMovieData->mMaterial.mData )
    {
      v32 = Illusion::Factory::NewMaterial("MovieNoAlpha", v28, 6u, 0i64, 0i64, 0i64);
      v33 = UFG::qStringHash32("MOVIEPLAYER", 0xFFFFFFFF);
      LOWORD(v32[1].mNode.mChild[0]) = 0;
      HIDWORD(v32[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
      LODWORD(v32[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
      v32[1].mTypeUID = -1957338719;
      LODWORD(v32[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v33;
      *(_WORD *)&v32[1].mDebugName[12] = 0;
      *(_DWORD *)&v32[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
      *(_DWORD *)&v32[1].mDebugName[4] = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
      LODWORD(v32[1].mStateBlockMask.mFlags[1]) = -1958479169;
      LODWORD(v32[1].mStateBlockMask.mFlags[0]) = 0;
      LOWORD(v32[1].mMaterialUser.mOffset) = 0;
      *(&v32[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
      v32[1].mNumParams = UFG::qStringHash32("texDiffuse2", 0xFFFFFFFF);
      LODWORD(v32[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = -1958479169;
      v32[2].mNode.mUID = 0;
      LOWORD(v32[2].mTypeUID) = 0;
      HIDWORD(v32[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
      LODWORD(v32[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32(
                                                                           "texDiffuseWorld",
                                                                           0xFFFFFFFF);
      *((_DWORD *)&v32[2].UFG::qResourceData + 22) = -1958479169;
      *(_DWORD *)&v32[2].mDebugName[28] = 0;
      LOWORD(v32[2].mStateBlockMask.mFlags[1]) = 0;
      HIDWORD(v32[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
      LODWORD(v32[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
      LODWORD(v32[3].mNode.mChild[1]) = 315097330;
      LODWORD(v32[3].mNode.mChild[0]) = 662883558;
      LOWORD(v32[3].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 0;
      *(&v32[3].mNode.mUID + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
      v32[3].mNode.mUID = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
      *(_DWORD *)&v32[3].mDebugName[20] = 1002903008;
      *(_DWORD *)&v32[3].mDebugName[12] = 1660426324;
      v34 = UFG::qResourceWarehouse::Instance();
      UFG::qResourceWarehouse::Add(v34, v32);
      v35 = this->mMovieData;
      v36 = `UFG::qGetResourceInventory<Illusion::Material>::`2::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Material>::`2::result )
      {
        v37 = UFG::qResourceWarehouse::Instance();
        v36 = UFG::qResourceWarehouse::GetInventory(v37, 0xB4C26312);
        `UFG::qGetResourceInventory<Illusion::Material>::`2::result = v36;
      }
      UFG::qResourceHandle::Init(&v35->mMaterial, 0xB4C26312, v28, v36);
    }
    UFG::qMutex::Lock(&stru_142042A80);
    mPrev = UFG::TheMovieHandler.mActiveMovies.mNode.mPrev;
    UFG::TheMovieHandler.mActiveMovies.mNode.mPrev->mNext = this;
    this->mPrev = mPrev;
    this->mNext = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)&UFG::TheMovieHandler;
    UFG::TheMovieHandler.mActiveMovies.mNode.mPrev = this;
    this->mbFirstFrame = 1;
    UFG::qMutex::Unlock(&stru_142042A80);
    return 1i64;
  }
  else
  {
    this->mFlags |= 1u;
    Error = (const char *)BinkGetError();
    UFG::qPrintf("Bink error: %s\n", Error);
    return 0i64;
  }
}

// File Line: 379
// RVA: 0x221B00
__int64 __fastcall UFG::MoviePlayer::InitInMemory(
        UFG::MoviePlayer *this,
        UFG::MovieResourceData *data,
        unsigned int flags)
{
  UFG::allocator::free_link *v5; // rax
  UFG::MovieData *v6; // rdi
  const char *Error; // rax
  UFG::qResourceWarehouse *v9; // rax
  UFG::qResourceInventory *Inventory; // rdi
  int v11; // ebp
  __int64 v12; // rsi
  unsigned int *p_mRTextureUID; // r14
  int v14; // esi
  __int64 v15; // rdi
  unsigned int v16; // ebp
  UFG::MovieData *mMovieData; // rdi
  UFG::qResourceInventory *v18; // rax
  UFG::qResourceWarehouse *v19; // rax
  Illusion::Material *v20; // rsi
  int v21; // edi
  UFG::qResourceWarehouse *v22; // rax
  UFG::MovieData *v23; // rdi
  UFG::qResourceInventory *v24; // rax
  UFG::qResourceWarehouse *v25; // rax
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *mPrev; // rax

  this->mFlags = flags | 0x10;
  UFG::qResourceHandle::Init(&this->mTargetTexture, 0x8B43FABF, data->mTargetTextureUID);
  this->mFilename = data->mDebugName;
  BinkSetIOSize(0i64);
  v5 = UFG::qMalloc(0x140ui64, "MovieData", 0i64);
  v6 = (UFG::MovieData *)v5;
  if ( v5 )
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v5[8]);
  else
    v6 = 0i64;
  this->mMovieData = v6;
  this->mMovieData->mBinkHandle = (BINK *)BinkOpen(&data[1], 85984256i64);
  if ( this->mMovieData->mBinkHandle )
  {
    v9 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v9, 0x8B43FABF);
    BinkGetFrameBuffersInfo(this->mMovieData->mBinkHandle, &this->mMovieData->mBinkFrameBuffers);
    v11 = 0;
    if ( this->mMovieData->mBinkFrameBuffers.TotalFrames > 0 )
    {
      v12 = 0i64;
      p_mRTextureUID = &data->mBuffers[0].mRTextureUID;
      do
      {
        this->mMovieData->mBuffer[v12].mTextureY = (Illusion::Texture *)Inventory->vfptr->Get(
                                                                          Inventory,
                                                                          *(p_mRTextureUID - 1));
        this->mMovieData->mBuffer[v12].mTextureR = (Illusion::Texture *)Inventory->vfptr->Get(
                                                                          Inventory,
                                                                          *p_mRTextureUID);
        this->mMovieData->mBuffer[v12].mTextureB = (Illusion::Texture *)Inventory->vfptr->Get(
                                                                          Inventory,
                                                                          p_mRTextureUID[1]);
        ++v11;
        p_mRTextureUID += 3;
        ++v12;
      }
      while ( v11 < this->mMovieData->mBinkFrameBuffers.TotalFrames );
    }
    UFG::MoviePlayer::LockTextures(this);
    v14 = 0;
    if ( this->mMovieData->mBinkFrameBuffers.TotalFrames > 0 )
    {
      v15 = 0i64;
      do
      {
        Illusion::ITexturePlat::Unlock(this->mMovieData->mBuffer[v15].mTextureY);
        Illusion::ITexturePlat::Unlock(this->mMovieData->mBuffer[v15].mTextureR);
        Illusion::ITexturePlat::Unlock(this->mMovieData->mBuffer[v15].mTextureB);
        ++v14;
        ++v15;
      }
      while ( v14 < this->mMovieData->mBinkFrameBuffers.TotalFrames );
    }
    v16 = UFG::qStringHashUpper32("MovieNoAlpha", -1);
    mMovieData = this->mMovieData;
    v18 = `UFG::qGetResourceInventory<Illusion::Material>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Material>::`2::result )
    {
      v19 = UFG::qResourceWarehouse::Instance();
      v18 = UFG::qResourceWarehouse::GetInventory(v19, 0xB4C26312);
      `UFG::qGetResourceInventory<Illusion::Material>::`2::result = v18;
    }
    UFG::qResourceHandle::Init(&mMovieData->mMaterial, 0xB4C26312, v16, v18);
    if ( !this->mMovieData->mMaterial.mData )
    {
      v20 = Illusion::Factory::NewMaterial("MovieNoAlpha", v16, 6u, 0i64, 0i64, 0i64);
      v21 = UFG::qStringHash32("MOVIEPLAYER", 0xFFFFFFFF);
      LOWORD(v20[1].mNode.mChild[0]) = 0;
      HIDWORD(v20[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
      LODWORD(v20[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
      v20[1].mTypeUID = -1957338719;
      LODWORD(v20[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v21;
      *(_WORD *)&v20[1].mDebugName[12] = 0;
      *(_DWORD *)&v20[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
      *(_DWORD *)&v20[1].mDebugName[4] = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
      LODWORD(v20[1].mStateBlockMask.mFlags[1]) = -1958479169;
      LODWORD(v20[1].mStateBlockMask.mFlags[0]) = 0;
      LOWORD(v20[1].mMaterialUser.mOffset) = 0;
      *(&v20[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
      v20[1].mNumParams = UFG::qStringHash32("texDiffuse2", 0xFFFFFFFF);
      LODWORD(v20[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = -1958479169;
      v20[2].mNode.mUID = 0;
      LOWORD(v20[2].mTypeUID) = 0;
      HIDWORD(v20[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
      LODWORD(v20[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32(
                                                                           "texDiffuseWorld",
                                                                           0xFFFFFFFF);
      *((_DWORD *)&v20[2].UFG::qResourceData + 22) = -1958479169;
      *(_DWORD *)&v20[2].mDebugName[28] = 0;
      LOWORD(v20[2].mStateBlockMask.mFlags[1]) = 0;
      HIDWORD(v20[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
      LODWORD(v20[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
      LODWORD(v20[3].mNode.mChild[1]) = 315097330;
      LODWORD(v20[3].mNode.mChild[0]) = 662883558;
      LOWORD(v20[3].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 0;
      *(&v20[3].mNode.mUID + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
      v20[3].mNode.mUID = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
      *(_DWORD *)&v20[3].mDebugName[20] = 1002903008;
      *(_DWORD *)&v20[3].mDebugName[12] = 1660426324;
      v22 = UFG::qResourceWarehouse::Instance();
      UFG::qResourceWarehouse::Add(v22, v20);
      v23 = this->mMovieData;
      v24 = `UFG::qGetResourceInventory<Illusion::Material>::`2::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Material>::`2::result )
      {
        v25 = UFG::qResourceWarehouse::Instance();
        v24 = UFG::qResourceWarehouse::GetInventory(v25, 0xB4C26312);
        `UFG::qGetResourceInventory<Illusion::Material>::`2::result = v24;
      }
      UFG::qResourceHandle::Init(&v23->mMaterial, 0xB4C26312, v16, v24);
    }
    UFG::qMutex::Lock(&stru_142042A80);
    mPrev = UFG::TheMovieHandler.mActiveMovies.mNode.mPrev;
    UFG::TheMovieHandler.mActiveMovies.mNode.mPrev->mNext = this;
    this->mPrev = mPrev;
    this->mNext = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)&UFG::TheMovieHandler;
    UFG::TheMovieHandler.mActiveMovies.mNode.mPrev = this;
    UFG::qMutex::Unlock(&stru_142042A80);
    return 1i64;
  }
  else
  {
    this->mFlags |= 1u;
    Error = (const char *)BinkGetError();
    UFG::qPrintf("Bink error: %s\n", Error);
    return 0i64;
  }
}

// File Line: 465
// RVA: 0x222410
__int64 __fastcall UFG::MoviePlayer::Render(UFG::MoviePlayer *this, Render::View *view)
{
  unsigned int mFlags; // eax
  Illusion::Texture *mData; // rdi
  Illusion::Target *mTarget; // rdx
  _WORD *v7; // rdi
  UFG::MovieData *mMovieData; // rdx
  UFG::MovieData::Buffer *v9; // r14
  unsigned int mUID; // r8d
  UFG::qResourceData *v11; // rsi
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rax
  _WORD *v13; // rax
  unsigned int v14; // r8d
  UFG::qResourceData *v15; // rsi
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v16; // rax
  _WORD *v17; // rax
  unsigned int v18; // r8d
  UFG::qResourceData *v19; // rsi
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v20; // rax
  Illusion::CreateTargetParams params; // [rsp+60h] [rbp-C8h] BYREF
  Render::Poly poly; // [rsp+130h] [rbp+8h] BYREF

  mFlags = this->mFlags;
  if ( (mFlags & 1) == 0 || (mFlags & 4) != 0 )
  {
    if ( (mFlags & 0x10) != 0 && !this->mTarget )
    {
      mData = (Illusion::Texture *)this->mTargetTexture.mData;
      if ( !mData || UFG::qResourceHandle::IsDefault(&this->mTargetTexture) )
        return 0i64;
      Illusion::CreateTargetParams::CreateTargetParams(&params, mData->mDebugName, 0);
      params.textures[0] = mData;
      this->mTarget = Illusion::CreateTarget(&params);
      UFG::qString::~qString(&params.name);
    }
    mTarget = this->mTarget;
    v7 = 0i64;
    if ( mTarget )
      Render::View::BeginTarget(view, mTarget, "Movie", 0, 0, 0i64, 1, 0, 0, 0);
    mMovieData = this->mMovieData;
    v9 = &mMovieData->mBuffer[mMovieData->mBinkHandle->FrameBuffers->FrameNum == 0];
    mUID = v9->mTextureY->mNode.mUID;
    v11 = mMovieData->mMaterial.mData;
    if ( v11[2].mTypeUID != mUID )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v11[2].mNode.mUID, *(_DWORD *)&v11[2].mDebugName[4], mUID);
      mPrev = v11[1].mResourceHandles.mNode.mPrev;
      if ( mPrev )
        v13 = (_WORD *)((char *)&mPrev[7].mNext + (_QWORD)v11);
      else
        v13 = 0i64;
      *v13 |= 0x20u;
    }
    v14 = v9->mTextureR->mNode.mUID;
    v15 = this->mMovieData->mMaterial.mData;
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
    v19 = this->mMovieData->mMaterial.mData;
    if ( *(_DWORD *)&v19[3].mDebugName[20] != v18 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v19[3].mTypeUID, *(_DWORD *)&v19[3].mDebugName[28], v18);
      v20 = v19[1].mResourceHandles.mNode.mPrev;
      if ( v20 )
        v7 = (_WORD *)((char *)&v19[1].mResourceHandles + (_QWORD)v20);
      *v7 |= 0x20u;
    }
    if ( !this->mbFirstFrame || (this->mFlags & 0x10) != 0 || this->mMovieData->mBinkHandle->FrameNum >= 3 )
    {
      this->mbFirstFrame = 0;
      Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
      Render::View::Draw(view, &poly, (Illusion::Material *)this->mMovieData->mMaterial.mData, 0i64);
    }
    else
    {
      Render::View::Clear(view, &UFG::qColour::Black, 1u, 1.0, 1u);
    }
    if ( this->mTarget )
      Render::View::EndTarget(view);
  }
  return 0i64;
}

// File Line: 543
// RVA: 0x222000
void __fastcall UFG::MoviePlayer::LockTextures(UFG::MoviePlayer *this)
{
  UFG::MovieData *mMovieData; // rax
  unsigned int FrameNum; // r15d
  int v4; // ebp
  __int64 v5; // rdi
  __int64 v6; // rsi
  Illusion::ITexturePlat::LockType v7; // r14d
  Illusion::TextureLockInfo info; // [rsp+30h] [rbp-38h] BYREF

  mMovieData = this->mMovieData;
  FrameNum = mMovieData->mBinkFrameBuffers.FrameNum;
  v4 = 0;
  if ( mMovieData->mBinkFrameBuffers.TotalFrames > 0 )
  {
    v5 = 0i64;
    v6 = 0i64;
    do
    {
      v7 = LOCK_MODIFY|LOCK_OVERWRITE;
      if ( v4 != FrameNum )
        v7 = LOCK_OVERWRITE;
      if ( Illusion::ITexturePlat::Lock(mMovieData->mBuffer[v6].mTextureY, v7, &info, 0, 0) )
      {
        this->mMovieData->mBinkFrameBuffers.Frames[v5].YPlane.Buffer = info.mData;
        this->mMovieData->mBinkFrameBuffers.Frames[v5].YPlane.BufferPitch = info.mLinePitch;
      }
      if ( Illusion::ITexturePlat::Lock(this->mMovieData->mBuffer[v6].mTextureR, v7, &info, 0, 0) )
      {
        this->mMovieData->mBinkFrameBuffers.Frames[v5].cRPlane.Buffer = info.mData;
        this->mMovieData->mBinkFrameBuffers.Frames[v5].cRPlane.BufferPitch = info.mLinePitch;
      }
      if ( Illusion::ITexturePlat::Lock(this->mMovieData->mBuffer[v6].mTextureB, v7, &info, 0, 0) )
      {
        this->mMovieData->mBinkFrameBuffers.Frames[v5].cBPlane.Buffer = info.mData;
        this->mMovieData->mBinkFrameBuffers.Frames[v5].cBPlane.BufferPitch = info.mLinePitch;
      }
      mMovieData = this->mMovieData;
      ++v4;
      ++v6;
      ++v5;
    }
    while ( v4 < mMovieData->mBinkFrameBuffers.TotalFrames );
  }
  BinkRegisterFrameBuffers(this->mMovieData->mBinkHandle, &this->mMovieData->mBinkFrameBuffers);
}

// File Line: 575
// RVA: 0x222BD0
void __fastcall UFG::MoviePlayer::UnlockTextures(UFG::MoviePlayer *this)
{
  UFG::MovieData *mMovieData; // rax
  int v2; // edi
  __int64 v4; // rbx

  mMovieData = this->mMovieData;
  v2 = 0;
  if ( mMovieData->mBinkFrameBuffers.TotalFrames > 0 )
  {
    v4 = 0i64;
    do
    {
      Illusion::ITexturePlat::Unlock(mMovieData->mBuffer[v4].mTextureY);
      Illusion::ITexturePlat::Unlock(this->mMovieData->mBuffer[v4].mTextureR);
      Illusion::ITexturePlat::Unlock(this->mMovieData->mBuffer[v4].mTextureB);
      mMovieData = this->mMovieData;
      ++v2;
      ++v4;
    }
    while ( v2 < mMovieData->mBinkFrameBuffers.TotalFrames );
  }
}

// File Line: 590
// RVA: 0x222200
void __fastcall UFG::MoviePlayer::PlayFromStart(UFG::MoviePlayer *this, bool loop)
{
  bool v4; // zf
  UFG::MovieData *mMovieData; // rcx

  if ( this->mIsPaused )
  {
    v4 = (this->mFlags & 1) == 0;
    this->mIsPaused = 0;
    if ( v4 )
      BinkPause(this->mMovieData->mBinkHandle, 0i64);
  }
  if ( loop )
    this->mFlags |= 4u;
  else
    this->mFlags &= ~4u;
  mMovieData = this->mMovieData;
  this->mFlags &= ~1u;
  BinkGoto(mMovieData->mBinkHandle, 1i64);
}

// File Line: 630
// RVA: 0x222E80
__int64 __fastcall UFG::MoviePlayer::Update(UFG::MoviePlayer *this, bool inMovieLocation)
{
  unsigned int mFlags; // eax
  BINK *mBinkHandle; // rbx

  mFlags = this->mFlags;
  if ( (mFlags & 1) != 0 && (mFlags & 4) == 0 )
    return 0i64;
  if ( !this->mIsPaused )
  {
    mBinkHandle = this->mMovieData->mBinkHandle;
    UFG::MoviePlayer::LockTextures(this);
    if ( inMovieLocation || (this->mFlags & 0x10) == 0 )
    {
      BinkDoFrame(mBinkHandle);
      if ( !(unsigned int)BinkWait(mBinkHandle) )
      {
        while ( (unsigned int)BinkShouldSkip(mBinkHandle) )
        {
          BinkNextFrame(mBinkHandle);
          BinkDoFrame(mBinkHandle);
          if ( mBinkHandle->FrameNum == mBinkHandle->Frames )
            this->mFlags |= 1u;
        }
        BinkNextFrame(mBinkHandle);
      }
    }
    if ( mBinkHandle->FrameNum == mBinkHandle->Frames )
      this->mFlags |= 1u;
    UFG::MoviePlayer::UnlockTextures(this);
  }
  return 1i64;
}

// File Line: 718
// RVA: 0x2211F0
void __fastcall UFG::MoviePlayer::Close(UFG::MoviePlayer *this)
{
  UFG::MovieData *mMovieData; // rax
  __int64 v3; // rcx
  int v4; // ebp
  __int64 v5; // rsi
  __int64 v6; // rdi
  UFG::MovieData *v7; // rcx
  UFG::MovieData *v8; // rcx
  UFG::MovieData *v9; // rcx
  UFG::MovieData *v10; // rdi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v12; // rax
  UFG::MovieHandler *mNext; // rax
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *mPrev; // rdx
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v15; // rax

  mMovieData = this->mMovieData;
  if ( mMovieData )
  {
    if ( (this->mFlags & 0x10) != 0 )
    {
      if ( this->mTarget )
      {
        v3 = 2i64 * unk_142042AB0;
        ++unk_142042AB0;
        *((_QWORD *)&unk_142042AB8 + v3) = this->mTarget;
        *((_DWORD *)&unk_142042AB8 + 2 * v3 + 2) = Illusion::gEngine.mFrameCount;
      }
    }
    else if ( mMovieData->mBinkHandle )
    {
      Illusion::IEnginePlat::WaitUntilGPUDone(&Illusion::gEngine);
      v4 = 0;
      if ( this->mMovieData->mBinkFrameBuffers.TotalFrames > 0 )
      {
        v5 = 0i64;
        v6 = 0i64;
        do
        {
          v7 = this->mMovieData;
          if ( v7->mBinkFrameBuffers.Frames[v6].YPlane.Allocate )
            Illusion::DeleteTexture((AMD_HD3D *)v7->mBuffer[v5].mTextureY, 1);
          v8 = this->mMovieData;
          if ( v8->mBinkFrameBuffers.Frames[v6].cRPlane.Allocate )
            Illusion::DeleteTexture((AMD_HD3D *)v8->mBuffer[v5].mTextureR, 1);
          v9 = this->mMovieData;
          if ( v9->mBinkFrameBuffers.Frames[v6].cBPlane.Allocate )
            Illusion::DeleteTexture((AMD_HD3D *)v9->mBuffer[v5].mTextureB, 1);
          ++v4;
          ++v6;
          ++v5;
        }
        while ( v4 < this->mMovieData->mBinkFrameBuffers.TotalFrames );
      }
    }
    BinkClose(this->mMovieData->mBinkHandle);
    v10 = this->mMovieData;
    if ( v10 )
    {
      Inventory = `UFG::qGetResourceInventory<Illusion::Material>::`2::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Material>::`2::result )
      {
        v12 = UFG::qResourceWarehouse::Instance();
        Inventory = UFG::qResourceWarehouse::GetInventory(v12, 0xB4C26312);
        `UFG::qGetResourceInventory<Illusion::Material>::`2::result = Inventory;
      }
      UFG::qResourceHandle::Close(&v10->mMaterial, Inventory);
      UFG::qResourceHandle::~qResourceHandle(&v10->mMaterial);
      operator delete[](v10);
    }
    this->mMovieData = 0i64;
    this->mIsPaused = 0;
    UFG::qMutex::Lock(&stru_142042A80);
    mNext = (UFG::MovieHandler *)off_142042A68;
    if ( off_142042A68 != (UFG::MoviePlayer *)&UFG::TheMovieHandler )
    {
      while ( mNext != (UFG::MovieHandler *)this )
      {
        mNext = (UFG::MovieHandler *)mNext->mActiveMovies.mNode.mNext;
        if ( mNext == &UFG::TheMovieHandler )
          goto LABEL_24;
      }
      mPrev = this->mPrev;
      v15 = this->mNext;
      mPrev->mNext = v15;
      v15->mPrev = mPrev;
      this->mPrev = this;
      this->mNext = this;
    }
LABEL_24:
    UFG::qMutex::Unlock(&stru_142042A80);
  }
}

// File Line: 820
// RVA: 0x222970
void __fastcall UFG::MoviePlayer::SetAudioVolume(UFG::MoviePlayer *this, unsigned int track, unsigned int volume)
{
  unsigned int v3; // ebx

  v3 = volume;
  if ( UFG::TiDo::sm_isMuted )
    v3 = 0;
  if ( Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(
         (hkGeometryUtils::IVertices *)this,
         track,
         volume) )
  {
    BinkSetVolume(this->mMovieData->mBinkHandle, track, v3);
  }
}

// File Line: 834
// RVA: 0x221460
float __fastcall UFG::MovieHandler::GetNonInMemMovieLength(UFG::MovieHandler *this)
{
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *mNext; // rax
  float v3; // xmm6_4

  UFG::qMutex::Lock(&stru_142042A80);
  mNext = this->mActiveMovies.mNode.mNext;
  if ( mNext == (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)this )
  {
LABEL_6:
    v3 = 0.0;
  }
  else
  {
    while ( ((__int64)mNext[3].mNext & 0x10) != 0 )
    {
      mNext = mNext->mNext;
      if ( mNext == (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)this )
        goto LABEL_6;
    }
    v3 = (float)((float)((float)SHIDWORD(mNext[4].mNext[6].mPrev[1].mPrev)
                       / (float)SLODWORD(mNext[4].mNext[6].mPrev[1].mNext))
               * (float)SLODWORD(mNext[4].mNext[6].mPrev->mNext))
       * 0.001;
  }
  UFG::qMutex::Unlock(&stru_142042A80);
  return v3;
}

// File Line: 852
// RVA: 0x221F90
__int64 __fastcall UFG::MovieHandler::IsPlayingNonInMemMovies(UFG::MovieHandler *this)
{
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *mNext; // rax
  unsigned __int8 v3; // bl

  UFG::qMutex::Lock(&stru_142042A80);
  mNext = this->mActiveMovies.mNode.mNext;
  if ( mNext == (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)this )
  {
LABEL_6:
    v3 = 0;
  }
  else
  {
    while ( ((__int64)mNext[3].mNext & 0x10) != 0 )
    {
      mNext = mNext->mNext;
      if ( mNext == (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)this )
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
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *i; // rbx

  UFG::qMutex::Lock(&stru_142042A80);
  for ( i = this->mActiveMovies.mNode.mNext; i != (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)this; i = i->mNext )
  {
    LOBYTE(i[5].mPrev) = 1;
    if ( ((__int64)i[3].mNext & 1) == 0 )
      BinkPause(i[4].mNext[6].mPrev, 1i64);
  }
  UFG::qMutex::Unlock(&stru_142042A80);
}

// File Line: 879
// RVA: 0x222C40
void __fastcall UFG::MovieHandler::Unpause(UFG::MovieHandler *this)
{
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *i; // rbx

  UFG::qMutex::Lock(&stru_142042A80);
  for ( i = this->mActiveMovies.mNode.mNext; i != (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)this; i = i->mNext )
  {
    LOBYTE(i[5].mPrev) = 0;
    if ( ((__int64)i[3].mNext & 1) == 0 )
      BinkPause(i[4].mNext[6].mPrev, 0i64);
  }
  UFG::qMutex::Unlock(&stru_142042A80);
}

// File Line: 890
// RVA: 0x2229C0
void __fastcall UFG::MovieHandler::SetVolumeAll(UFG::MovieHandler *this, unsigned int volume)
{
  int v4; // edx
  hkGeometryUtils::IVertices *v5; // rcx
  int v6; // r8d
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *i; // rbx
  unsigned int v8; // edi

  UFG::qMutex::Lock(&stru_142042A80);
  for ( i = this->mActiveMovies.mNode.mNext; i != (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)this; i = i->mNext )
  {
    v8 = volume;
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
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *mNext; // rdx
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *mPrev; // rcx
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v6; // rax
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
  __int64 *v20; // [rsp+28h] [rbp-20h] BYREF
  UFG::MoviePlayer *v21; // [rsp+30h] [rbp-18h]

  v20 = (__int64 *)&v20;
  v21 = (UFG::MoviePlayer *)&v20;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mActiveMoviesMutex);
  for ( ; (UFG::MovieHandler *)this->mActiveMovies.mNode.mNext != this; v20 = (__int64 *)mNext )
  {
    mNext = this->mActiveMovies.mNode.mNext;
    mPrev = mNext->mPrev;
    v6 = mNext->mNext;
    mPrev->mNext = v6;
    v6->mPrev = mPrev;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    v7 = v20;
    v20[1] = (__int64)mNext;
    mNext->mPrev = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)v7;
    mNext->mNext = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)&v20;
  }
  for ( i = v21; v21 != (UFG::MoviePlayer *)&v20; i = v21 )
  {
    v9 = i->mPrev;
    v10 = i->mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    i->mPrev = i;
    i->mNext = i;
    if ( UFG::MoviePlayer::Update(i, inMovieLocation) )
    {
      v12 = this->mActiveMovies.mNode.mPrev;
      v12->mNext = i;
      i->mPrev = v12;
      i->mNext = &this->mActiveMovies.mNode;
      this->mActiveMovies.mNode.mPrev = i;
    }
    else
    {
      v11 = this->mFinishedMovies.mNode.mPrev;
      v11->mNext = i;
      i->mPrev = v11;
      i->mNext = &this->mFinishedMovies.mNode;
      this->mFinishedMovies.mNode.mPrev = i;
    }
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mActiveMoviesMutex);
  for ( j = v21; v21 != (UFG::MoviePlayer *)&v20; j = v21 )
  {
    v14 = j->mPrev;
    v15 = j->mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    j->mPrev = j;
    j->mNext = j;
    UFG::MoviePlayer::Close(j);
    UFG::qResourceHandle::~qResourceHandle(&j->mTargetTexture);
    v16 = j->mPrev;
    v17 = j->mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    j->mPrev = j;
    j->mNext = j;
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
  UFG::qList<UFG::MoviePlayer,UFG::MoviePlayer,1,0> *p_mFinishedMovies; // rbx
  UFG::MoviePlayer *mNext; // rcx
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *mPrev; // rdx
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v5; // rax
  unsigned int mFrameCount; // ebp
  __int64 i; // rbx
  __int64 v8; // rdi
  __int64 v9; // rcx

  p_mFinishedMovies = &this->mFinishedMovies;
  if ( (UFG::qList<UFG::MoviePlayer,UFG::MoviePlayer,1,0> *)this->mFinishedMovies.mNode.mNext != &this->mFinishedMovies )
  {
    do
    {
      mNext = (UFG::MoviePlayer *)this->mFinishedMovies.mNode.mNext;
      mPrev = mNext->mPrev;
      v5 = mNext->mNext;
      mPrev->mNext = v5;
      v5->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      UFG::MoviePlayer::Close(mNext);
    }
    while ( (UFG::qList<UFG::MoviePlayer,UFG::MoviePlayer,1,0> *)p_mFinishedMovies->mNode.mNext != p_mFinishedMovies );
  }
  mFrameCount = Illusion::gEngine.mFrameCount;
  for ( i = 0i64; (unsigned int)i < this->mDoneTargets.size; i = (unsigned int)(i + 1) )
  {
    if ( mFrameCount >= this->mDoneTargets.p[i].mMovieDeleteFrame + 3 )
    {
      v8 = (unsigned int)i;
      Illusion::DeleteTarget((AMD_HD3D *)this->mDoneTargets.p[(unsigned int)i].mTarget, 0);
      v9 = --this->mDoneTargets.size;
      LODWORD(i) = i - 1;
      this->mDoneTargets.p[v8].mTarget = this->mDoneTargets.p[this->mDoneTargets.size].mTarget;
      *(_QWORD *)&this->mDoneTargets.p[v8].mMovieDeleteFrame = *(_QWORD *)&this->mDoneTargets.p[v9].mMovieDeleteFrame;
    }
  }
}

// File Line: 983
// RVA: 0x222A70
void __fastcall UFG::MovieHandler::ShouldAllowStreaming(
        UFG::MovieHandler *this,
        bool *game_streaming,
        bool *disk_caching)
{
  unsigned int v6; // ebx
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *i; // rcx
  int mNext; // eax
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *k; // rbx
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v10; // rcx
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *j; // rbx
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v12; // rcx
  char v13[44]; // [rsp+28h] [rbp-50h] BYREF
  unsigned int v14; // [rsp+54h] [rbp-24h]
  int v15; // [rsp+58h] [rbp-20h]

  UFG::qMutex::Lock(&stru_142042A80);
  *game_streaming = 1;
  *disk_caching = 1;
  v6 = 100;
  for ( i = this->mActiveMovies.mNode.mNext; i != (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)this; i = i->mNext )
  {
    if ( ((__int64)i[3].mNext & 0x10) == 0 && i[4].mNext )
    {
      mNext = (int)i[3].mNext;
      if ( (mNext & 1) == 0 || (mNext & 4) != 0 )
        *disk_caching = 0;
      BinkGetRealtime(i[4].mNext[6].mPrev, v13, 0i64);
      if ( v14 )
        v6 = 100 * v15 / v14;
      break;
    }
  }
  if ( UFG::gBinkStreamingMode )
  {
    if ( v6 < 0x1E )
    {
      UFG::gBinkStreamingMode = STREAMING_MODE_BINK;
      for ( j = this->mActiveMovies.mNode.mNext; j != (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)this; j = j->mNext )
      {
        if ( ((__int64)j[3].mNext & 0x10) == 0 )
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
    UFG::gBinkStreamingMode = STREAMING_MODE_GAME;
    for ( k = this->mActiveMovies.mNode.mNext; k != (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)this; k = k->mNext )
    {
      if ( ((__int64)k[3].mNext & 0x10) == 0 )
      {
        v10 = k[4].mNext;
        if ( v10 )
          BinkControlBackgroundIO(v10[6].mPrev, 1i64);
      }
    }
  }
  *game_streaming = UFG::gBinkStreamingMode == STREAMING_MODE_GAME;
  UFG::qMutex::Unlock(&stru_142042A80);
}

// File Line: 1058
// RVA: 0x222650
void __fastcall UFG::MovieHandler::RenderFullScreen(UFG::MovieHandler *this, Render::View *view, bool render_over_ui)
{
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *i; // rbx

  for ( i = this->mActiveMovies.mNode.mNext; i != (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)this; i = i->mNext )
  {
    if ( ((__int64)i[3].mNext & 0x10) == 0 )
    {
      if ( BYTE2(i[5].mPrev) )
      {
        if ( !render_over_ui )
          continue;
LABEL_7:
        UFG::MoviePlayer::Render((UFG::MoviePlayer *)i, view);
        continue;
      }
      if ( !render_over_ui )
        goto LABEL_7;
    }
  }
}

// File Line: 1072
// RVA: 0x2226C0
void __fastcall UFG::MovieHandler::RenderOffScreen(UFG::MovieHandler *this, Illusion::SubmitContext *submit_context)
{
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *mNext; // rbx
  Render::ViewSettings *Identity; // rax
  int v6; // eax
  Illusion::Texture *v7; // rdi
  Illusion::Target *mPrev; // rdx
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v9; // rdx
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v10; // rsi
  unsigned int v11; // r8d
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v12; // rdi
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v13; // rax
  _WORD *v14; // rax
  unsigned int v15; // r8d
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v16; // rdi
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v17; // rax
  _WORD *v18; // rax
  unsigned int v19; // r8d
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v20; // rdi
  UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *v21; // rax
  _WORD *v22; // rax
  Illusion::CreateTargetParams params; // [rsp+60h] [rbp-268h] BYREF
  Render::View v24; // [rsp+110h] [rbp-1B8h] BYREF
  Render::Poly poly; // [rsp+2D0h] [rbp+8h] BYREF

  mNext = this->mActiveMovies.mNode.mNext;
  if ( mNext != (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)this )
  {
    while ( 1 )
    {
      Identity = Render::ViewSettings::GetIdentity();
      Render::View::View(&v24, Identity, submit_context);
      v6 = (int)mNext[3].mNext;
      if ( (v6 & 0x10) != 0 && ((v6 & 1) == 0 || (v6 & 4) != 0) )
      {
        if ( (v6 & 0x10) == 0 || mNext[1].mPrev )
          goto LABEL_10;
        v7 = (Illusion::Texture *)mNext[2].mNext;
        if ( v7 )
        {
          if ( !UFG::qResourceHandle::IsDefault((UFG::qResourceHandle *)&mNext[1].mNext) )
            break;
        }
      }
LABEL_34:
      mNext = mNext->mNext;
      if ( mNext == (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)this )
        return;
    }
    Illusion::CreateTargetParams::CreateTargetParams(&params, v7->mDebugName, 0);
    params.textures[0] = v7;
    mNext[1].mPrev = (UFG::qNode<UFG::MoviePlayer,UFG::MoviePlayer> *)Illusion::CreateTarget(&params);
    UFG::qString::~qString(&params.name);
LABEL_10:
    mPrev = (Illusion::Target *)mNext[1].mPrev;
    if ( mPrev )
      Render::View::BeginTarget(&v24, mPrev, "Movie", 0, 0, 0i64, 1, 0, 0, 0);
    v9 = mNext[4].mNext;
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
    v16 = mNext[4].mNext[5].mPrev;
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
    v20 = mNext[4].mNext[5].mPrev;
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
    if ( !BYTE1(mNext[5].mPrev) || ((__int64)mNext[3].mNext & 0x10) != 0 || HIDWORD(mNext[4].mNext[6].mPrev->mNext) >= 3 )
    {
      BYTE1(mNext[5].mPrev) = 0;
      Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
      Render::View::Draw(&v24, &poly, (Illusion::Material *)mNext[4].mNext[5].mPrev, 0i64);
    }
    else
    {
      Render::View::Clear(&v24, &UFG::qColour::Black, 1u, 1.0, 1u);
    }
    if ( mNext[1].mPrev )
      Render::View::EndTarget(&v24);
    goto LABEL_34;
  }
}1.0, 1

