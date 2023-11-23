// File Line: 260
// RVA: 0x643190
void __fastcall UFG::WheeledVehicleManager::RoadSpawningRecord::RoadSpawningRecord(
        UFG::WheeledVehicleManager::RoadSpawningRecord *this)
{
  this->mPrev = this;
  this->mNext = this;
  *(_QWORD *)&this->m_SpawnWeight = 0i64;
  this->m_NumCarsToSpawn = 0;
  this->m_pSubSegment = 0i64;
}

