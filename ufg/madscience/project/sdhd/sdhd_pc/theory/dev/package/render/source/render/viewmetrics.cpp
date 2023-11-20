// File Line: 22
// RVA: 0x1A330
void __fastcall Render::ViewMetrics::Reset(Render::ViewMetrics *this)
{
  UFG::qMemSet(this, 0, 0x80u);
}

// File Line: 28
// RVA: 0x1A2E0
void __fastcall Render::ViewMetrics::BeginTarget(Render::ViewMetrics *this)
{
  this->mTargetTimingStartTicks = UFG::qGetTicks();
}

// File Line: 34
// RVA: 0x1A300
void __fastcall Render::ViewMetrics::EndTarget(Render::ViewMetrics *this)
{
  Render::ViewMetrics *v1; // rbx
  unsigned __int64 v2; // rax

  v1 = this;
  v2 = UFG::qGetTicks();
  v1->mTargetTiming = UFG::qGetTickTime(v1->mTargetTimingStartTicks, v2) + v1->mTargetTiming;
}

// File Line: 39
// RVA: 0x1A210
void __fastcall Render::ViewMetrics::Accumulate(Render::ViewMetrics *this, Render::ViewMetrics *other)
{
  this->mTargetTimingStartTicks += other->mTargetTimingStartTicks;
  this->mTargetTiming = other->mTargetTiming + this->mTargetTiming;
  this->mDrawScenery = other->mDrawScenery + this->mDrawScenery;
  this->mDrawComposite = other->mDrawComposite + this->mDrawComposite;
  this->mDrawLights = other->mDrawLights + this->mDrawLights;
  this->mClouds = other->mClouds + this->mClouds;
  this->mNumCompositeProcessed += other->mNumCompositeProcessed;
  this->mNumModelsProcessed += other->mNumModelsProcessed;
  this->mNumModelsRendered += other->mNumModelsRendered;
  this->mNumSkinnedModelsRendered += other->mNumSkinnedModelsRendered;
  this->mNumRigidModelsRendered += other->mNumRigidModelsRendered;
  this->mNumMeshsRendered += other->mNumMeshsRendered;
  this->mNumLightsProcessed += other->mNumLightsProcessed;
  this->mNumLightsNearTotal += other->mNumLightsNearTotal;
  this->mNumLightsNearRendered += other->mNumLightsNearRendered;
  this->mNumLightsStencilTotal += other->mNumLightsStencilTotal;
  this->mNumLightsStencilRendered += other->mNumLightsStencilRendered;
  this->mNumLightsFarTotal += other->mNumLightsFarTotal;
  this->mNumLightsFarRendered += other->mNumLightsFarRendered;
  this->mNumLightCards += other->mNumLightCards;
  this->mNumShadowsRendered += other->mNumShadowsRendered;
  this->mNumCloudsRendered += other->mNumCloudsRendered;
  this->mNumParticles += other->mNumParticles;
  this->mNumLargeParticleBatches += other->mNumLargeParticleBatches;
  this->mNumSmallParticleBatches += other->mNumSmallParticleBatches;
}

