// File Line: 102
// RVA: 0x8D060
void __fastcall Illusion::ShaderPermutation::ShaderPermutation(Illusion::ShaderPermutation *this)
{
  Illusion::ShaderPermutation *v1; // rbx

  v1 = this;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mShaderHandle.mPrev);
  v1->mStateBlockMask.mFlags[0] = 0i64;
  v1->mStateBlockMask.mFlags[1] = 0i64;
}

// File Line: 214
// RVA: 0x8D0A0
void __fastcall Illusion::ShaderTemplate::ShaderTemplate(Illusion::ShaderTemplate *this)
{
  Illusion::ShaderTemplate *v1; // rbx
  UFG::BitFlags128 *v2; // rax
  signed __int64 v3; // rdx

  v1 = this;
  UFG::qResourceData::qResourceData((UFG::qResourceData *)&this->mNode);
  v1->mPermutationStateBlockMask.mFlags[0] = 0i64;
  v1->mPermutationStateBlockMask.mFlags[1] = 0i64;
  v1->mComponentLookup.mNumComponentBits = 0;
  v2 = v1->mComponentLookup.mComponentBit;
  v3 = 11i64;
  do
  {
    v2->mFlags[1] = 0i64;
    v2->mFlags[0] = 0i64;
    ++v2;
    --v3;
  }
  while ( v3 );
  v1->mShaderPermutations = 0i64;
}

