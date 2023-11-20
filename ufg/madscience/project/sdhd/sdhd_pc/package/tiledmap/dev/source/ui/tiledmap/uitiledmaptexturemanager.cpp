// File Line: 35
// RVA: 0xBCFF0
void __fastcall UFG::UITiledMapTextureManager::UITiledMapTextureManager(UFG::UITiledMapTextureManager *this, unsigned int mapWidth, unsigned int mapHeight, unsigned int tileSize)
{
  unsigned int v4; // ebx
  unsigned int v5; // edi
  unsigned int v6; // esi
  UFG::UITiledMapTextureManager *v7; // r14
  UFG::qList<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo,1,0> *v8; // ST38_8
  unsigned __int64 v9; // rsi
  signed __int64 v10; // rax
  unsigned __int8 v11; // cf
  unsigned __int64 v12; // rax
  char *v13; // rax
  signed __int64 v14; // rbx
  signed __int64 v15; // rdi
  unsigned __int64 v16; // rax
  int v17; // edi
  signed __int64 v18; // rax
  unsigned __int64 v19; // rax
  char *v20; // rax

  v4 = tileSize;
  v5 = mapHeight;
  v6 = mapWidth;
  v7 = this;
  *(_WORD *)&this->mActive = 257;
  v8 = &this->mTileTextureInfo;
  v8->mNode.mPrev = &v8->mNode;
  v8->mNode.mNext = &v8->mNode;
  this->old_col = -1;
  this->old_row = -1;
  UFG::qMemSet(this->mTileTag, 0, 0xCu);
  v7->mMapWidth = v6;
  v7->mMapHeight = v5;
  v7->mTileSize = v4;
  v9 = v5 * v6;
  v7->mTileCount = v9;
  v10 = 40 * v9;
  if ( !is_mul_ok(v9, 0x28ui64) )
    v10 = -1i64;
  v11 = __CFADD__(v10, 8i64);
  v12 = v10 + 8;
  if ( v11 )
    v12 = -1i64;
  v13 = UFG::qMalloc(v12, "UITiledMapTextureManager", 0i64);
  v14 = 0i64;
  if ( v13 )
  {
    *(_DWORD *)v13 = v9;
    v15 = (signed __int64)(v13 + 8);
    `eh vector constructor iterator(v13 + 8, 0x28ui64, v9, (void (__fastcall *)(void *))UFG::qString::qString);
  }
  else
  {
    v15 = 0i64;
  }
  v7->mTileNames = (UFG::qString *)v15;
  v16 = 4i64 * v7->mTileCount;
  if ( !is_mul_ok(v7->mTileCount, 4ui64) )
    v16 = -1i64;
  v7->mTileUIDs = (unsigned int *)UFG::qMalloc(v16, "UITiledMapTextureManager", 0i64);
  v17 = v7->mTileCount;
  v18 = 32i64 * v7->mTileCount;
  if ( !is_mul_ok(v7->mTileCount, 0x20ui64) )
    v18 = -1i64;
  v11 = __CFADD__(v18, 8i64);
  v19 = v18 + 8;
  if ( v11 )
    v19 = -1i64;
  v20 = UFG::qMalloc(v19, "UITiledMapTextureManager", 0i64);
  if ( v20 )
  {
    *(_DWORD *)v20 = v17;
    v14 = (signed __int64)(v20 + 8);
    `eh vector constructor iterator(
      v20 + 8,
      0x20ui64,
      v17,
      (void (__fastcall *)(void *))Illusion::TextureHandle::TextureHandle);
  }
  v7->mTextureHandles = (Illusion::TextureHandle *)v14;
}

// File Line: 53
// RVA: 0xBD850
void __fastcall UFG::UITiledMapTextureManager::~UITiledMapTextureManager(UFG::UITiledMapTextureManager *this)
{
  UFG::UITiledMapTextureManager *v1; // rdi
  UFG::qString *v2; // rcx
  unsigned int *v3; // rbx
  Illusion::TextureHandle *v4; // rcx
  unsigned int *v5; // rbx
  UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *v6; // rcx
  UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *v7; // rax

  v1 = this;
  v2 = this->mTileNames;
  if ( v2 )
  {
    v3 = &v2[-1].mStringHash32;
    `eh vector destructor iterator(
      v2,
      0x28ui64,
      v2[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v3);
  }
  v1->mTileNames = 0i64;
  operator delete[](v1->mTileUIDs);
  v1->mTileUIDs = 0i64;
  v4 = v1->mTextureHandles;
  if ( v4 )
  {
    v5 = &v4[-1].mNameUID;
    `eh vector destructor iterator(
      v4,
      0x20ui64,
      v4[-1].mNameUID,
      (void (__fastcall *)(void *))Illusion::TextureHandle::~TextureHandle);
    operator delete[](v5);
  }
  v1->mTextureHandles = 0i64;
  UFG::UITiledMapTextureManager::ReleaseAllTextures(v1);
  UFG::qList<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo,1,0>::DeleteNodes(&v1->mTileTextureInfo);
  v6 = v1->mTileTextureInfo.mNode.mPrev;
  v7 = v1->mTileTextureInfo.mNode.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v1->mTileTextureInfo.mNode.mPrev = &v1->mTileTextureInfo.mNode;
  v1->mTileTextureInfo.mNode.mNext = &v1->mTileTextureInfo.mNode;
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
void __fastcall UFG::UITiledMapTextureManager::SetPlayerPosition(UFG::UITiledMapTextureManager *this, UFG::MinimapPoint2f *pos)
{
  UFG::UITiledMapTextureManager *v2; // rdi
  signed int v3; // er9
  signed int v4; // er8
  __m128 v5; // xmm1
  __m128 v6; // xmm2
  signed int v7; // ecx
  signed int v8; // ecx
  UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *v9; // rax
  signed __int64 i; // r14
  __int64 v11; // r12
  unsigned int v12; // ecx
  unsigned int v13; // er15
  unsigned int v14; // esi
  unsigned int v15; // ebp
  UFG::qString *v16; // rax
  signed __int64 v17; // rbx
  unsigned int v18; // ebx
  UFG::qResourceHandle *v19; // r13
  UFG::qResourceInventory *v20; // rax
  UFG::qResourceWarehouse *v21; // rax
  UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *j; // rax
  UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *v23; // rdi
  UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *v24; // rsi
  const char *v25; // rbx
  UFG::UIScreenTextureManager *v26; // rax
  UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *v27; // rdx
  UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *v28; // rax
  UFG::qString result; // [rsp+38h] [rbp-60h]
  signed int v30; // [rsp+A0h] [rbp+8h]
  signed int v31; // [rsp+B0h] [rbp+18h]
  unsigned int v32; // [rsp+B8h] [rbp+20h]

  v2 = this;
  if ( this->mActive )
  {
    v3 = 0;
    v31 = 0;
    v4 = 0;
    v30 = 0;
    if ( this->mStreamingEnabled )
    {
      v5 = (__m128)(unsigned int)FLOAT_1_0;
      v5.m128_f32[0] = 1.0 / (float)(signed int)this->mTileSize;
      v6 = v5;
      v6.m128_f32[0] = v5.m128_f32[0] * pos->x;
      v7 = (signed int)v6.m128_f32[0];
      if ( (signed int)v6.m128_f32[0] != 0x80000000 && (float)v7 != v6.m128_f32[0] )
        v6.m128_f32[0] = (float)(v7 - (_mm_movemask_ps(_mm_unpacklo_ps(v6, v6)) & 1));
      v3 = (signed int)v6.m128_f32[0];
      v31 = (signed int)v6.m128_f32[0];
      v5.m128_f32[0] = v5.m128_f32[0] * pos->y;
      v8 = (signed int)v5.m128_f32[0];
      if ( (signed int)v5.m128_f32[0] != 0x80000000 && (float)v8 != v5.m128_f32[0] )
        v5.m128_f32[0] = (float)(v8 - (_mm_movemask_ps(_mm_unpacklo_ps(v5, v5)) & 1));
      v4 = (signed int)v5.m128_f32[0];
      v30 = (signed int)v5.m128_f32[0];
    }
    if ( v2->old_col != v3 || v2->old_row != v4 )
    {
      UFG::UITiledMapTextureManager::mShouldRefresh = 1;
      v2->old_col = v3;
      v2->old_row = v4;
      v9 = v2->mTileTextureInfo.mNode.mNext;
      for ( i = (signed __int64)&v2->mTileTextureInfo;
            v9 != (UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *)i;
            v9 = v9->mNext )
      {
        LOBYTE(v9[1].mNext) = 0;
      }
      v11 = 0i64;
      v12 = 0;
      v32 = 0;
      if ( v2->mMapHeight )
      {
        do
        {
          v13 = 0;
          if ( v2->mMapWidth )
          {
            do
            {
              if ( (unsigned int)v11 < v2->mTileCount )
              {
                v14 = v2->mTileSize * (v13 + v3);
                v15 = v2->mTileSize * (v12 + v4);
                v16 = UFG::qString::FormatEx(&result, "img://MMAP_CHIP_%d_%d%s", v14, v15, v2->mTileTag);
                v17 = (unsigned int)v11 + 4 * v11;
                UFG::qString::Set((UFG::qString *)((char *)v2->mTileNames + 8 * v17), v16->mData, v16->mLength, 0i64, 0);
                UFG::qString::~qString(&result);
                v2->mTileUIDs[v11] = UFG::qStringHashUpper32(
                                       (const char *)(*((_QWORD *)&v2->mTileNames->mData + v17) + 6i64),
                                       0xFFFFFFFF);
                v18 = v2->mTileUIDs[v11];
                v19 = (UFG::qResourceHandle *)&v2->mTextureHandles[(unsigned int)v11].mPrev;
                v20 = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
                if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
                {
                  v21 = UFG::qResourceWarehouse::Instance();
                  v20 = UFG::qResourceWarehouse::GetInventory(v21, 0x8B43FABF);
                  `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = v20;
                }
                UFG::qResourceHandle::Init(v19, 0x8B43FABF, v18, v20);
                for ( j = v2->mTileTextureInfo.mNode.mNext;
                      j != (UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *)i;
                      j = j->mNext )
                {
                  if ( LODWORD(j[1].mPrev) == v14 && HIDWORD(j[1].mPrev) == v15 )
                  {
                    LOBYTE(j[1].mNext) = 1;
                    goto LABEL_27;
                  }
                }
                UFG::UITiledMapTextureManager::LoadTexture(v2, v14, v15);
LABEL_27:
                v11 = (unsigned int)(v11 + 1);
                v12 = v32;
                v4 = v30;
                v3 = v31;
              }
              ++v13;
            }
            while ( v13 < v2->mMapWidth );
          }
          v32 = ++v12;
        }
        while ( v12 < v2->mMapHeight );
      }
      if ( UFG::UITiledMapTextureManager::mShouldRefresh )
      {
        v23 = v2->mTileTextureInfo.mNode.mNext;
        if ( v23 != (UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *)i )
        {
          do
          {
            v24 = v23->mNext;
            if ( !LOBYTE(v23[1].mNext) )
            {
              v25 = (const char *)v23[3].mNext;
              v26 = UFG::UIScreenTextureManager::Instance();
              UFG::UIScreenTextureManager::ReleaseTexturePack(v26, v25);
              UFG::qString::~qString((UFG::qString *)&v23[2]);
              v27 = v23->mPrev;
              v28 = v23->mNext;
              v27->mNext = v28;
              v28->mPrev = v27;
              v23->mPrev = v23;
              v23->mNext = v23;
              operator delete[](v23);
              --UFG::UITiledMapTextureManager::mNumTilesLoaded;
            }
            v23 = v24;
          }
          while ( v24 != (UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *)i );
        }
      }
    }
    else
    {
      UFG::UITiledMapTextureManager::mShouldRefresh = 0;
    }
  }
}

// File Line: 173
// RVA: 0xC49C0
char *__fastcall UFG::UITiledMapTextureManager::GetTileName(UFG::UITiledMapTextureManager *this, unsigned int index)
{
  char *result; // rax

  if ( index >= this->mTileCount )
    result = 0i64;
  else
    result = this->mTileNames[index].mData;
  return result;
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
char __fastcall UFG::UITiledMapTextureManager::LoadTexture(UFG::UITiledMapTextureManager *this, int u, int v)
{
  int v3; // edi
  int v4; // esi
  UFG::UITiledMapTextureManager *v5; // rbp
  char *v6; // rax
  char *v7; // rbx
  UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *v8; // rax
  UFG::qString *v9; // rax
  const char *v10; // rbx
  UFG::UIScreenTextureManager *v11; // rax
  __int64 lengthb; // [rsp+20h] [rbp-58h]
  __int64 v14; // [rsp+28h] [rbp-50h]
  UFG::qString result; // [rsp+48h] [rbp-30h]

  v3 = v;
  v4 = u;
  v5 = this;
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
  *((_DWORD *)v7 + 4) = v4;
  *((_DWORD *)v7 + 5) = v3;
  v7[24] = 1;
  v8 = v5->mTileTextureInfo.mNode.mPrev;
  v8->mNext = (UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *)v7;
  *(_QWORD *)v7 = v8;
  *((_QWORD *)v7 + 1) = (char *)v5 + 48;
  v5->mTileTextureInfo.mNode.mPrev = (UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *)v7;
  if ( v4 < 0
    || v3 < 0
    || (float)v4 > UFG::UITiledMapMath::WorldGeo.TextureWidth
    || (float)v3 > UFG::UITiledMapMath::WorldGeo.TextureHeight )
  {
    return 0;
  }
  LODWORD(v14) = v3;
  LODWORD(lengthb) = v4;
  v9 = UFG::qString::FormatEx(
         &result,
         "%s\\Row_%d\\TexturePack_%d_%d%s.perm.bin",
         UFG::gMinimapTextureDir,
         (unsigned int)v3,
         lengthb,
         v14,
         v5->mTileTag);
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
  UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *v1; // rdi
  UFG::qList<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo,1,0> *v2; // rsi
  const char *v3; // rbx
  UFG::UIScreenTextureManager *v4; // rax
  UFG::qList<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo,1,0> *i; // rax
  UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *v6; // rdx
  UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *v7; // rcx

  v1 = this->mTileTextureInfo.mNode.mNext;
  v2 = &this->mTileTextureInfo;
  if ( v1 != (UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *)&this->mTileTextureInfo )
  {
    do
    {
      v3 = (const char *)v1[3].mNext;
      v4 = UFG::UIScreenTextureManager::Instance();
      UFG::UIScreenTextureManager::ReleaseTexturePack(v4, v3);
      v1 = v1->mNext;
    }
    while ( v1 != (UFG::qNode<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo> *)v2 );
  }
  for ( i = (UFG::qList<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo,1,0> *)v2->mNode.mNext;
        i != v2;
        i = (UFG::qList<UFG::UIMapTileTextureInfo,UFG::UIMapTileTextureInfo,1,0> *)v2->mNode.mNext )
  {
    v6 = i->mNode.mPrev;
    v7 = i->mNode.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    i->mNode.mPrev = &i->mNode;
    i->mNode.mNext = &i->mNode;
  }
  UFG::UITiledMapTextureManager::mNumTilesLoaded = 0;
}

