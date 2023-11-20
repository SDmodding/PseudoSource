// File Line: 25
// RVA: 0x9FA90
UFG::ComponentIDDesc *__fastcall UFG::TerrainCollisionComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::TerrainCollisionComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::TerrainCollisionComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::TerrainCollisionComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::TerrainCollisionComponent::_DescInit = 1;
    UFG::TerrainCollisionComponent::_TypeUID = UFG::TerrainCollisionComponent::_TypeIDesc.mChildBitMask | (UFG::TerrainCollisionComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::TerrainCollisionComponent::_TerrainCollisionComponentTypeUID = UFG::TerrainCollisionComponent::_TypeIDesc.mChildBitMask | (UFG::TerrainCollisionComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::TerrainCollisionComponent::_TypeIDesc;
}

