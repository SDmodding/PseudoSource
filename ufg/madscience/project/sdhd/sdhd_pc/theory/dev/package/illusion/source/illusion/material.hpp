// File Line: 146
// RVA: 0x8CDE0
void __fastcall Illusion::Material::Material(Illusion::Material *this, const char *name, unsigned int name_uid, unsigned int num_params)
{
  unsigned int v4; // edi
  Illusion::Material *v5; // rsi
  unsigned int v6; // ebx
  signed __int64 v7; // rcx

  v4 = num_params;
  v5 = this;
  UFG::qResourceData::qResourceData((UFG::qResourceData *)&this->mNode, 0xB4C26312, name_uid, name);
  v5->mNumParams = v4;
  v6 = 0;
  if ( v4 )
  {
    do
    {
      v7 = (signed __int64)&v5[1] + 56 * v6;
      if ( v7 )
      {
        *(_DWORD *)(v7 + 8) = 0;
        UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)(v7 + 16));
      }
      ++v6;
    }
    while ( v6 < v5->mNumParams );
  }
  v5->mStateBlockMask.mFlags[1] = 0i64;
  v5->mStateBlockMask.mFlags[0] = 0i64;
}

// File Line: 147
// RVA: 0x8CE90
void __fastcall Illusion::Material::Material(Illusion::Material *this)
{
  Illusion::Material *v1; // rdi
  unsigned int v2; // ebx
  signed __int64 v3; // rcx

  v1 = this;
  UFG::qResourceData::qResourceData((UFG::qResourceData *)&this->mNode);
  v2 = 0;
  if ( v1->mNumParams )
  {
    do
    {
      v3 = (signed __int64)&v1[1] + 56 * v2;
      if ( v3 )
      {
        *(_DWORD *)(v3 + 8) = 0;
        UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)(v3 + 16));
      }
      ++v2;
    }
    while ( v2 < v1->mNumParams );
  }
  v1->mStateBlockMask.mFlags[1] = 0i64;
  v1->mStateBlockMask.mFlags[0] = 0i64;
}

// File Line: 199
// RVA: 0x9360
void __fastcall Illusion::Material::UpdateParam(Illusion::Material *this, __int16 param_index, unsigned int resource_type_uid, unsigned int resource_name_uid)
{
  Illusion::Material *v4; // rbx
  signed __int64 v5; // rdx
  __int64 v6; // rax

  v4 = this;
  v5 = 7i64 * (unsigned int)param_index;
  if ( *(_DWORD *)((char *)&this[1].mResourceHandles.mNode.mNext + v5 * 8) != resource_name_uid )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&this[1].mNode.mChild[v5 + 1],
      *((_DWORD *)&this[1].mNode + 2 * v5 + 12),
      resource_name_uid);
    v6 = v4->mMaterialUser.mOffset;
    if ( v6 )
      *(_WORD *)((char *)&v4->mMaterialUser.mOffset + v6) |= 0x20u;
    else
      LOWORD(MEMORY[0]) = MEMORY[0] | 0x20;
  }
}

// File Line: 264
// RVA: 0x8CF10
void __fastcall Illusion::MaterialTable::MaterialTable(Illusion::MaterialTable *this)
{
  Illusion::MaterialTable *v1; // rdi
  unsigned int v2; // ebx
  signed __int64 v3; // rax

  v1 = this;
  UFG::qResourceData::qResourceData((UFG::qResourceData *)&this->mNode);
  v2 = 0;
  if ( v1->mNumMaterials )
  {
    do
    {
      v3 = 32i64 * v2;
      if ( (Illusion::MaterialTable *)((char *)&v1[1] + v3) )
        UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)((char *)&v1[1] + v3));
      ++v2;
    }
    while ( v2 < v1->mNumMaterials );
  }
}

