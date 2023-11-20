// File Line: 14
// RVA: 0x2663A0
void __fastcall UFG::NavAvoidanceStrategyNone::SetLocalModuleFor(UFG::NavAvoidanceStrategyNone *this, UFG::NavComponent *pNavComponent)
{
  UFG::NavComponent::SetLocalModule<UFG::NavModuleLocalNone>(pNavComponent);
}

