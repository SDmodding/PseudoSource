// File Line: 260
// RVA: 0x643190
void __fastcall UFG::WheeledVehicleManager::RoadSpawningRecord::RoadSpawningRecord(UFG::WheeledVehicleManager::RoadSpawningRecord *this)
{
  this->mPrev = (UFG::qNode<UFG::WheeledVehicleManager::RoadSpawningRecord,UFG::WheeledVehicleManager::RoadSpawningRecord> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::WheeledVehicleManager::RoadSpawningRecord,UFG::WheeledVehicleManager::RoadSpawningRecord> *)&this->mPrev;
  *(_QWORD *)&this->m_SpawnWeight = 0i64;
  this->m_NumCarsToSpawn = 0;
  this->m_pSubSegment = 0i64;
}

