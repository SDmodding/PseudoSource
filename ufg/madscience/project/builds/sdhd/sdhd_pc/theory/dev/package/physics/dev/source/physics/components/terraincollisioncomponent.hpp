// File Line: 25
// RVA: 0x9FA90
UFG::ComponentIDDesc *__fastcall UFG::TerrainCollisionComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::TerrainCollisionComponent::_DescInit )
  {
    UFG::TerrainCollisionComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::TerrainCollisionComponent::_DescInit = 1;
    UFG::TerrainCollisionComponent::_TypeUID = UFG::TerrainCollisionComponent::_TypeIDesc.mChildBitMask | (UFG::TerrainCollisionComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::TerrainCollisionComponent::_TerrainCollisionComponentTypeUID = UFG::TerrainCollisionComponent::_TypeIDesc.mChildBitMask | (UFG::TerrainCollisionComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::TerrainCollisionComponent::_TypeIDesc;
}

