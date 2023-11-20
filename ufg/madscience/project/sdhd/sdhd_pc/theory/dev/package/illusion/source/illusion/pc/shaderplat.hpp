// File Line: 195
// RVA: 0xA159B0
void __fastcall Illusion::ShaderConstBufInfo::ShaderConstBufInfo(Illusion::ShaderConstBufInfo *this)
{
  this->mNameHash = 0;
  this->mVarCount = 0;
  this->mVarInfo = 0i64;
}

// File Line: 197
// RVA: 0xA16610
void __fastcall Illusion::ShaderConstBufInfo::~ShaderConstBufInfo(Illusion::ShaderConstBufInfo *this)
{
  Illusion::ShaderConstBufInfo *v1; // rbx
  Illusion::ShaderConstBufInfo::VarInfo *v2; // rcx

  v1 = this;
  v2 = this->mVarInfo;
  if ( v2 )
  {
    operator delete[](v2);
    v1->mVarInfo = 0i64;
  }
}

