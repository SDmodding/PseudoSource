// File Line: 47
// RVA: 0xB8160
void hkProductFeatures::initialize(void)
{
  hkOptionalComponent::request(&hkOptionalComponent_hkpHeightFieldAgent);
  hkOptionalComponent::request(&hkOptionalComponent_hkpSimulation);
  hkOptionalComponent::request(&hkOptionalComponent_hkpContinuousSimulation);
  hkOptionalComponent::request(&hkOptionalComponent_hkpMultiThreadedSimulation);
  hkOptionalComponent::request(&hkOptionalComponent_hkpAccurateInertiaTensorComputer);
  hkOptionalComponent::request(&hkOptionalComponent_hkp3AxisSweep);
  hkOptionalComponent::request(&hkOptionalComponent_hkpTreeBroadPhase);
  hkOptionalComponent::request(&hkOptionalComponent_hkpTreeBroadPhase32);
  hkOptionalComponent::request(&hkOptionalComponent_hkpSampledHeightField_AllCasts);
}

