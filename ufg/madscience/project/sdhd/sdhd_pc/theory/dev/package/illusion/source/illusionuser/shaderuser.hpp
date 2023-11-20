// File Line: 52
// RVA: 0xA159C0
void __fastcall Illusion::ShaderUser::ShaderUser(Illusion::ShaderUser *this)
{
  Illusion::ShaderUser *v1; // rbx

  v1 = this;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mOverride_OutputDepth.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v1->mOverride_OutputDepthAlpha.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v1->mOverride_OutputDepthAlphaWind.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v1->mOverride_OutputDepthWind.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v1->mOverride_OutputHighlight.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v1->mShaderTemplateHandle.mPrev);
}

