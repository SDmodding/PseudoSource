// File Line: 86
// RVA: 0xFB8C0
void __fastcall UFG::qSteadyState<UFG::FlowfieldMass,1>::~qSteadyState<UFG::FlowfieldMass,1>(
        UFG::qSteadyState<UFG::FlowfieldMass,1> *this)
{
  if ( this->mActive )
    this->mActive = 0;
}

