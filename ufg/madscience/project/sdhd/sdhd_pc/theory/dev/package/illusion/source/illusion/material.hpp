// File Line: 146
// RVA: 0x8CDE0
void __fastcall Illusion::Material::Material(
        Illusion::Material *this,
        const char *name,
        unsigned int name_uid,
        unsigned int num_params)
{
  unsigned int i; // ebx
  char *v7; // rcx

  UFG::qResourceData::qResourceData(this, 0xB4C26312, name_uid, name);
  this->mNumParams = num_params;
  for ( i = 0; i < this->mNumParams; ++i )
  {
    v7 = (char *)&this[1] + 56 * i;
    if ( v7 )
    {
      *((_DWORD *)v7 + 2) = 0;
      UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)(v7 + 16));
    }
  }
  this->mStateBlockMask.mFlags[1] = 0i64;
  this->mStateBlockMask.mFlags[0] = 0i64;
}

// File Line: 147
// RVA: 0x8CE90
void __fastcall Illusion::Material::Material(Illusion::Material *this)
{
  unsigned int i; // ebx
  char *v3; // rcx

  UFG::qResourceData::qResourceData(this);
  for ( i = 0; i < this->mNumParams; ++i )
  {
    v3 = (char *)&this[1] + 56 * i;
    if ( v3 )
    {
      *((_DWORD *)v3 + 2) = 0;
      UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)(v3 + 16));
    }
  }
  this->mStateBlockMask.mFlags[1] = 0i64;
  this->mStateBlockMask.mFlags[0] = 0i64;
}

// File Line: 199
// RVA: 0x9360
void __fastcall Illusion::Material::UpdateParam(
        Illusion::Material *this,
        __int16 param_index,
        unsigned int resource_type_uid,
        unsigned int resource_name_uid)
{
  __int64 v5; // rdx
  __int64 mOffset; // rax

  v5 = 7i64 * (unsigned int)param_index;
  if ( *(_DWORD *)((char *)&this[1].mResourceHandles.UFG::qResourceData::mNode.mNext + v5 * 8) != resource_name_uid )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&this[1].mNode.mChild[v5 + 1],
      *((_DWORD *)&this[1].mNode + 2 * v5 + 12),
      resource_name_uid);
    mOffset = this->mMaterialUser.mOffset;
    if ( mOffset )
      *(_WORD *)((char *)&this->mMaterialUser.mOffset + mOffset) |= 0x20u;
    else
      LOWORD(MEMORY[0]) = MEMORY[0] | 0x20;
  }
}

// File Line: 264
// RVA: 0x8CF10
void __fastcall Illusion::MaterialTable::MaterialTable(Illusion::MaterialTable *this)
{
  unsigned int i; // ebx
  UFG::qResourceHandle *v3; // rcx

  UFG::qResourceData::qResourceData(this);
  for ( i = 0; i < this->mNumMaterials; ++i )
  {
    v3 = (UFG::qResourceHandle *)(&this[1].mNode + i);
    if ( v3 )
      UFG::qResourceHandle::qResourceHandle(v3);
  }
}

