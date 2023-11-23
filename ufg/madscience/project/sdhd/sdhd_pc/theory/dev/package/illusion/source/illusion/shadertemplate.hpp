// File Line: 102
// RVA: 0x8D060
void __fastcall Illusion::ShaderPermutation::ShaderPermutation(Illusion::ShaderPermutation *this)
{
  UFG::qResourceHandle::qResourceHandle(&this->mShaderHandle);
  this->mStateBlockMask.mFlags[0] = 0i64;
  this->mStateBlockMask.mFlags[1] = 0i64;
}

// File Line: 214
// RVA: 0x8D0A0
void __fastcall Illusion::ShaderTemplate::ShaderTemplate(Illusion::ShaderTemplate *this)
{
  UFG::BitFlags128 *mComponentBit; // rax
  __int64 v3; // rdx

  UFG::qResourceData::qResourceData(this);
  this->mPermutationStateBlockMask.mFlags[0] = 0i64;
  this->mPermutationStateBlockMask.mFlags[1] = 0i64;
  this->mComponentLookup.mNumComponentBits = 0;
  mComponentBit = this->mComponentLookup.mComponentBit;
  v3 = 11i64;
  do
  {
    mComponentBit->mFlags[1] = 0i64;
    mComponentBit->mFlags[0] = 0i64;
    ++mComponentBit;
    --v3;
  }
  while ( v3 );
  this->mShaderPermutations = 0i64;
}

