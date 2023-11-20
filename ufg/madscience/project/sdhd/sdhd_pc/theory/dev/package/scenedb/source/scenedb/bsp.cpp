// File Line: 39
// RVA: 0x14701F0
__int64 UFG::_dynamic_initializer_for__gBSPInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&UFG::gBSPInventory.vfptr,
    "BSPInventory",
    0x45ED23E5u,
    0x4F05B59Au,
    0,
    0);
  UFG::gBSPInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::BSPInventory::`vftable;
  return atexit(UFG::_dynamic_atexit_destructor_for__gBSPInventory__);
}

// File Line: 75
// RVA: 0x236790
UFG::BSPInventory *__fastcall UFG::BSP::getInventory()
{
  return &UFG::gBSPInventory;
}

// File Line: 108
// RVA: 0x232350
void __fastcall UFG::BSP::GetAABB2D(UFG::BSP *this, UFG::qVector2 *vAABBMin, UFG::qVector2 *vAABBMax)
{
  float v3; // xmm1_4
  float v4; // xmm1_4

  v3 = this->mAABBMin.y;
  vAABBMin->x = this->mAABBMin.x;
  vAABBMin->y = v3;
  v4 = this->mAABBMax.y;
  vAABBMax->x = this->mAABBMax.x;
  vAABBMax->y = v4;
}

// File Line: 114
// RVA: 0x232C20
UFG::BSPSpace *__fastcall UFG::BSP::GetSpaceFromPoint(UFG::BSP *this, UFG::qVector3 *position, bool force_result, bool dbg_print_serials)
{
  __int64 v4; // rbx
  float v5; // xmm4_4
  float v6; // xmm5_4
  UFG::qOffset64<UFG::BSPNode *> *v7; // r11
  signed __int64 v8; // r9
  UFG::BSP *v9; // r10
  __int64 v10; // rax
  float v11; // xmm6_4
  int v12; // ecx
  UFG::BSPNode *v13; // rdx
  float v14; // xmm2_4
  int v15; // ecx
  __int64 v16; // rax
  unsigned int *v17; // rax
  __int64 v18; // rax
  unsigned int *v19; // rax
  __int64 v20; // rcx
  __int64 v21; // rax
  signed __int64 v22; // rax
  __int64 v23; // rdx
  __int64 v24; // rcx
  __int64 v25; // rax
  signed __int64 v26; // rax
  __int64 v28; // rcx
  __int64 v29; // rax
  __int64 v30; // rcx

  v4 = this->mNodes.mOffset;
  v5 = position->x;
  v6 = position->y;
  v7 = &this->mNodes;
  v8 = 0i64;
  v9 = this;
  v10 = 0i64;
  v11 = position->z;
  do
  {
    while ( 1 )
    {
      v12 = 0;
      v13 = (UFG::BSPNode *)((char *)&v7[6 * v10] + v4);
      v14 = (float)((float)((float)(v6 - v13->mPosition.y) * v13->mNormal.y)
                  + (float)((float)(v5 - v13->mPosition.x) * v13->mNormal.x))
          + (float)((float)(v11 - v13->mPosition.z) * v13->mNormal.z);
      if ( v14 <= 0.001 )
      {
        LOBYTE(v12) = v14 >= -0.001;
        ++v12;
      }
      if ( v12 )
        break;
LABEL_7:
      v10 = v13->mNodeFwdIdx;
      if ( (_DWORD)v10 == -1 )
      {
        v16 = v13->mFaces.mOffset;
        if ( v16 )
          v17 = (unsigned int *)((char *)&v13->mFaces + v16);
        else
          v17 = 0i64;
        v28 = *v17;
        v29 = v9->mFaces.mOffset;
        if ( v29 )
          v22 = (signed __int64)&v9->mFaces + v29;
        else
          v22 = 0i64;
        v23 = v28;
LABEL_28:
        v30 = v9->mSpaces.mOffset;
        if ( v30 )
          v8 = (signed __int64)&v9->mSpaces + v30;
        v26 = 5i64 * *(unsigned int *)(v22 + 8 * v23);
        return (UFG::BSPSpace *)(v8 + 0x10 * v26);
      }
    }
    v15 = v12 - 1;
    if ( v15 )
    {
      if ( v15 != 1 )
        return 0i64;
      goto LABEL_7;
    }
    v10 = v13->mNodeBckIdx;
  }
  while ( (_DWORD)v10 != -1 );
  v18 = v13->mFaces.mOffset;
  if ( v18 )
    v19 = (unsigned int *)((char *)&v13->mFaces + v18);
  else
    v19 = 0i64;
  v20 = *v19;
  v21 = v9->mFaces.mOffset;
  if ( v21 )
    v22 = (signed __int64)&v9->mFaces + v21;
  else
    v22 = 0i64;
  v23 = v20;
  v24 = *(unsigned int *)(v22 + 8 * v20 + 4);
  if ( (_DWORD)v24 == -1 )
  {
    if ( !force_result )
      return 0i64;
    goto LABEL_28;
  }
  v25 = v9->mSpaces.mOffset;
  if ( v25 )
    v8 = (signed __int64)&v9->mSpaces + v25;
  v26 = 5 * v24;
  return (UFG::BSPSpace *)(v8 + 0x10 * v26);
}

// File Line: 192
// RVA: 0x1470190
__int64 UFG::_dynamic_initializer_for__gBSPDebugDataInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&UFG::gBSPDebugDataInventory.vfptr,
    "BSPDebugDataInventory",
    0xA076E719,
    0xE2C5C78C,
    0,
    0);
  UFG::gBSPDebugDataInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::BSPDebugDataInventory::`vftable;
  return atexit(UFG::_dynamic_atexit_destructor_for__gBSPDebugDataInventory__);
}

