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
  Illusion::ShaderConstBufInfo::VarInfo *mVarInfo; // rcx

  mVarInfo = this->mVarInfo;
  if ( mVarInfo )
  {
    operator delete[](mVarInfo);
    this->mVarInfo = 0i64;
  }
}

