// File Line: 35
// RVA: 0xBCFF0
void __fastcall UFG::UITiledMapTextureManager::UITiledMapTextureManager(
        UFG::UITiledMapTextureManager *this,
        unsigned int mapWidth,
        unsigned int mapHeight,
        unsigned int tileSize)
{
  unsigned __int64 v8; // rsi
  __int64 v9; // rax
  bool v10; // cf
  unsigned __int64 v11; // rax
  char *v12; // rax
  Illusion::TextureHandle *v13; // rbx
  UFG::qString *v14; // rdi
  unsigned __int64 v15; // rax
  unsigned int mTileCount; // edi
  __int64 v17; // rax
  unsigned __int64 v18; // rax
  char *v19; // rax

  *(_WORD *)&this->mActive = 257;
  this->mTileTextureInfo.mNode.mPrev = &this->mTileTextureInfo.mNode;
  this->mTileTextureInfo.mNode.mNext = &this->mTileTextureInfo.mNode;
  this->old_col = -1;
  this->old_row = -1;
  UFG::qMemSet(this->mTileTag, 0, 0xCu);
  this->mMapWidth = mapWidth;
  this->mMapHeight = mapHeight;
  this->mTileSize = tileSize;
  v8 = mapHeight * mapWidth;
  this->mTileCount = v8;
  v9 = 40 * v8;
  if ( !is_mul_ok(v8, 0x28ui64) )
    v9 = -1i64;
  v10 = __CFADD__(v9, 8i64);
  v11 = v9 + 8;
  if ( v10 )
    v11 = -1i64;
  v12 = UFG::qMalloc(v11, "UITiledMapTextureManager", 0i64);
  v13 = 0i64;
  if ( v12 )
  {
    *(_DWORD *)v12 = v8;
    v14 = (UFG::qString *)(v12 + 8);
    `eh vector constructor iterator(v12 + 8, 0x28ui64, v8, (void (__fastcall *)(void *))UFG::qString::qString);
  }
  else
  {
    v14 = 0i64;
  }
  this->mTileNames = v14;
  v15 = 4i64 * this->mTileCount;
  if ( !is_mul_ok(this->mTileCount, 4ui64) )
    v15 = -1i64;
  this->mTileUIDs = (unsigned int *)UFG::qMalloc(v15, "UITiledMapTextureManager", 0i64);
  mTileCount = this->mTileCount;
  v17 = 32i64 * mTileCount;
  if ( !is_mul_ok(mTileCount, 0x20ui64) )
    v17 = -1i64;
  v10 = __CFADD__(v17, 8i64);
  v18 = v17 + 8;
  if ( v10 )
    v18 = -1i64;
  v19 = UFG::qMalloc(v18, "UITiledMapTextureManager", 0i64);
  if ( v19 )
  {
    *(_DWORD *)v19 = mTileCount;
    v13 = (Illusion::TextureHandle *)(v19 + 8);
    `eh vector constructor iterator(
      v19 + 8,
      0x20ui64,
      mTileCount,
      (void (__fastcall *)(void *))Illusion::TextureHandle::TextureHandle);
  }
  this->mTextureHandles = v13;
}

// File Line: 53
// RVA: 0xBD850
void __fastcall UFG::UITiledMapTextureManager::~UITiledMapTextureManager(UFG::UITiledMapTextureManager *this)
{
  UFG::qString *mTileNames; // rcx
  unsigned int *p_mStringHash32; // rbx
  Illusion::TextureHandle *mTextureHandles; // rcx
  unsigned int *p_mNameUID; // rbx
  UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *mPrev; // rcx
  UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *mNext; // rax

  mTileNames = this->mTileNames;
  if ( mTileNames )
  {
    p_mStringHash32 = &mTileNames[-1].mStringHash32;
    `eh vector destructor iterator(
      mTileNames,
      0x28ui64,
      mTileNames[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](p_mStringHash32);
  }
  this->mTileNames = 0i64;
  operator delete[](this->mTileUIDs);
  this->mTileUIDs = 0i64;
  mTextureHandles = this->mTextureHandles;
  if ( mTextureHandles )
  {
    p_mNameUID = &mTextureHandles[-1].mNameUID;
    `eh vector destructor iterator(
      mTextureHandles,
      0x20ui64,
      mTextureHandles[-1].mNameUID,
      (void (__fastcall *)(void *))Illusion::TextureHandle::~TextureHandle);
    operator delete[](p_mNameUID);
  }
  this->mTextureHandles = 0i64;
  UFG::UITiledMapTextureManager::ReleaseAllTextures(this);
  UFG::qList<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo,1,0>::DeleteNodes(&this->mTileTextureInfo);
  mPrev = this->mTileTextureInfo.mNode.mPrev;
  mNext = this->mTileTextureInfo.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mTileTextureInfo.mNode.mPrev = &this->mTileTextureInfo.mNode;
  this->mTileTextureInfo.mNode.mNext = &this->mTileTextureInfo.mNode;
}

// File Line: 71
// RVA: 0xCA440
void __fastcall UFG::UITiledMapTextureManager::SetActive(UFG::UITiledMapTextureManager *this, bool active)
{
  if ( active != this->mActive )
  {
    this->mActive = active;
    if ( !active )
    {
      *(_QWORD *)&this->old_col = -1i64;
      UFG::UITiledMapTextureManager::ReleaseAllTextures(this);
    }
  }
}

// File Line: 85
// RVA: 0xCAE70
void __fastcall UFG::UITiledMapTextureManager::SetPlayerPosition(
        UFG::UITiledMapTextureManager *this,
        UFG::MinimapPoint2f *pos)
{
  int v3; // r9d
  int v4; // r8d
  __m128 v5; // xmm1
  __m128 v6; // xmm2
  int v7; // ecx
  int v8; // ecx
  UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *mNext; // rax
  UFG::qList<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo,1,0> *i; // r14
  __int64 v11; // r12
  unsigned int v12; // ecx
  unsigned int k; // r15d
  unsigned int v14; // esi
  unsigned int v15; // ebp
  UFG::qString *v16; // rax
  __int64 v17; // rbx
  unsigned int v18; // ebx
  Illusion::TextureHandle *v19; // r13
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v21; // rax
  UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *m; // rax
  UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *p_mNode; // rdi
  UFG::qList<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo,1,0> *v24; // rsi
  const char *v25; // rbx
  UFG::UIScreenTextureManager *v26; // rax
  UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *mPrev; // rdx
  UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *v28; // rax
  UFG::qString result; // [rsp+38h] [rbp-60h] BYREF
  int v30; // [rsp+A0h] [rbp+8h]
  int v31; // [rsp+B0h] [rbp+18h]
  unsigned int j; // [rsp+B8h] [rbp+20h]

  if ( this->mActive )
  {
    v3 = 0;
    v31 = 0;
    v4 = 0;
    v30 = 0;
    if ( this->mStreamingEnabled )
    {
      v5 = (__m128)(unsigned int)FLOAT_1_0;
      v5.m128_f32[0] = 1.0 / (float)(int)this->mTileSize;
      v6 = v5;
      v6.m128_f32[0] = v5.m128_f32[0] * pos->x;
      v7 = (int)v6.m128_f32[0];
      if ( (int)v6.m128_f32[0] != 0x80000000 && (float)v7 != v6.m128_f32[0] )
        v6.m128_f32[0] = (float)(v7 - (_mm_movemask_ps(_mm_unpacklo_ps(v6, v6)) & 1));
      v3 = (int)v6.m128_f32[0];
      v31 = (int)v6.m128_f32[0];
      v5.m128_f32[0] = v5.m128_f32[0] * pos->y;
      v8 = (int)v5.m128_f32[0];
      if ( (int)v5.m128_f32[0] != 0x80000000 && (float)v8 != v5.m128_f32[0] )
        v5.m128_f32[0] = (float)(v8 - (_mm_movemask_ps(_mm_unpacklo_ps(v5, v5)) & 1));
      v4 = (int)v5.m128_f32[0];
      v30 = (int)v5.m128_f32[0];
    }
    if ( this->old_col == v3 && this->old_row == v4 )
    {
      UFG::UITiledMapTextureManager::mShouldRefresh = 0;
    }
    else
    {
      UFG::UITiledMapTextureManager::mShouldRefresh = 1;
      this->old_col = v3;
      this->old_row = v4;
      mNext = this->mTileTextureInfo.mNode.mNext;
      for ( i = &this->mTileTextureInfo;
            mNext != (UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *)i;
            mNext = mNext->mNext )
      {
        LOBYTE(mNext[1].mNext) = 0;
      }
      v11 = 0i64;
      v12 = 0;
      for ( j = 0; v12 < this->mMapHeight; j = v12 )
      {
        for ( k = 0; k < this->mMapWidth; ++k )
        {
          if ( (unsigned int)v11 < this->mTileCount )
          {
            v14 = this->mTileSize * (k + v3);
            v15 = this->mTileSize * (v12 + v4);
            v16 = UFG::qString::FormatEx(&result, "img://MMAP_CHIP_%d_%d%s", v14, v15, this->mTileTag);
            v17 = (unsigned int)v11 + 4 * v11;
            UFG::qString::Set((UFG::qString *)((char *)this->mTileNames + 8 * v17), v16->mData, v16->mLength, 0i64, 0);
            UFG::qString::~qString(&result);
            this->mTileUIDs[v11] = UFG::qStringHashUpper32(
                                     (const char *)(*((_QWORD *)&this->mTileNames->mData + v17) + 6i64),
                                     0xFFFFFFFF);
            v18 = this->mTileUIDs[v11];
            v19 = &this->mTextureHandles[(unsigned int)v11];
            Inventory = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
            if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
            {
              v21 = UFG::qResourceWarehouse::Instance();
              Inventory = UFG::qResourceWarehouse::GetInventory(v21, 0x8B43FABF);
              `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = Inventory;
            }
            UFG::qResourceHandle::Init(v19, 0x8B43FABF, v18, Inventory);
            for ( m = this->mTileTextureInfo.mNode.mNext;
                  m != (UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *)i;
                  m = m->mNext )
            {
              if ( LODWORD(m[1].mPrev) == v14 && HIDWORD(m[1].mPrev) == v15 )
              {
                LOBYTE(m[1].mNext) = 1;
                goto LABEL_27;
              }
            }
            UFG::UITiledMapTextureManager::LoadTexture(this, v14, v15);
LABEL_27:
            v11 = (unsigned int)(v11 + 1);
            v12 = j;
            v4 = v30;
            v3 = v31;
          }
        }
        ++v12;
      }
      if ( UFG::UITiledMapTextureManager::mShouldRefresh )
      {
        p_mNode = this->mTileTextureInfo.mNode.mNext;
        if ( p_mNode != (UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *)i )
        {
          do
          {
            v24 = (UFG::qList<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo,1,0> *)p_mNode->mNext;
            if ( !LOBYTE(p_mNode[1].mNext) )
            {
              v25 = (const char *)p_mNode[3].mNext;
              v26 = UFG::UIScreenTextureManager::Instance();
              UFG::UIScreenTextureManager::ReleaseTexturePack(v26, v25);
              UFG::qString::~qString((UFG::qString *)&p_mNode[2]);
              mPrev = p_mNode->mPrev;
              v28 = p_mNode->mNext;
              mPrev->mNext = v28;
              v28->mPrev = mPrev;
              p_mNode->mPrev = p_mNode;
              p_mNode->mNext = p_mNode;
              operator delete[](p_mNode);
              --UFG::UITiledMapTextureManager::mNumTilesLoaded;
            }
            p_mNode = &v24->mNode;
          }
          while ( v24 != i );
        }
      }
    }
  }
}

// File Line: 173
// RVA: 0xC49C0
char *__fastcall UFG::UITiledMapTextureManager::GetTileName(UFG::UITiledMapTextureManager *this, unsigned int index)
{
  if ( index >= this->mTileCount )
    return 0i64;
  else
    return this->mTileNames[index].mData;
}

// File Line: 205
// RVA: 0xCB780
void __fastcall UFG::UITiledMapTextureManager::SetTileTag(UFG::UITiledMapTextureManager *this, const char *tag)
{
  UFG::qSPrintf(this->mTileTag, 12, "%s", tag);
}

// File Line: 211
// RVA: 0xCBA00
void __fastcall UFG::UITiledMapTextureManager::TextureLoadedCallback(UFG::DataStreamer::Handle *handle, void *param)
{
  ++UFG::UITiledMapTextureManager::mNumTilesLoaded;
  UFG::UITiledMapTextureManager::mShouldRefresh = 1;
}

// File Line: 239
// RVA: 0xC5E70
char __fastcall UFG::UITiledMapTextureManager::LoadTexture(UFG::UITiledMapTextureManager *this, int u, unsigned int v)
{
  char *v6; // rax
  char *v7; // rbx
  UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *mPrev; // rax
  UFG::qString *v9; // rax
  const char *v10; // rbx
  UFG::UIScreenTextureManager *v11; // rax
  UFG::qString result; // [rsp+48h] [rbp-30h] BYREF

  v6 = UFG::qMalloc(0x48ui64, "UIMapTileTextureInfo", 0x800ui64);
  v7 = v6;
  if ( v6 )
  {
    *(_QWORD *)v6 = v6;
    *((_QWORD *)v6 + 1) = v6;
    UFG::qString::qString((UFG::qString *)(v6 + 32));
  }
  else
  {
    v7 = 0i64;
  }
  *((_DWORD *)v7 + 4) = u;
  *((_DWORD *)v7 + 5) = v;
  v7[24] = 1;
  mPrev = this->mTileTextureInfo.mNode.mPrev;
  mPrev->mNext = (UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *)v7;
  *(_QWORD *)v7 = mPrev;
  *((_QWORD *)v7 + 1) = &this->mTileTextureInfo;
  this->mTileTextureInfo.mNode.mPrev = (UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *)v7;
  if ( u < 0
    || (v & 0x80000000) != 0
    || (float)u > UFG::UITiledMapMath::WorldGeo.TextureWidth
    || (float)(int)v > UFG::UITiledMapMath::WorldGeo.TextureHeight )
  {
    return 0;
  }
  v9 = UFG::qString::FormatEx(
         &result,
         "%s\\Row_%d\\TexturePack_%d_%d%s.perm.bin",
         UFG::gMinimapTextureDir,
         v,
         u,
         v,
         this->mTileTag);
  UFG::qString::Set((UFG::qString *)(v7 + 32), v9->mData, v9->mLength, 0i64, 0);
  UFG::qString::~qString(&result);
  v10 = (const char *)*((_QWORD *)v7 + 7);
  v11 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueTexturePackLoad(
    v11,
    v10,
    VERY_HIGH_PRIORITY,
    UFG::UITiledMapTextureManager::TextureLoadedCallback,
    0i64);
  return 1;
}

// File Line: 281
// RVA: 0xC7090
void __fastcall UFG::UITiledMapTextureManager::ReleaseAllTextures(UFG::UITiledMapTextureManager *this)
{
  UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *mNext; // rdi
  UFG::qList<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo,1,0> *i; // rsi
  const char *v3; // rbx
  UFG::UIScreenTextureManager *v4; // rax
  UFG::qList<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo,1,0> *j; // rax
  UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *mPrev; // rdx
  UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *v7; // rcx

  mNext = this->mTileTextureInfo.mNode.mNext;
  for ( i = &this->mTileTextureInfo;
        mNext != (UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *)i;
        mNext = mNext->mNext )
  {
    v3 = (const char *)mNext[3].mNext;
    v4 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::ReleaseTexturePack(v4, v3);
  }
  for ( j = (UFG::qList<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo,1,0> *)i->mNode.mNext;
        j != i;
        j = (UFG::qList<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo,1,0> *)i->mNode.mNext )
  {
    mPrev = j->mNode.mPrev;
    v7 = j->mNode.mNext;
    mPrev->mNext = v7;
    v7->mPrev = mPrev;
    j->mNode.mPrev = &j->mNode;
    j->mNode.mNext = &j->mNode;
  }
  UFG::UITiledMapTextureManager::mNumTilesLoaded = 0;
}

