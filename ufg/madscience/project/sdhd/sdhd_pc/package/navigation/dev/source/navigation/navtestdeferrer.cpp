// File Line: 45
// RVA: 0x265400
bool __fastcall UFG::TestDeferrer::IsStale(UFG::TestDeferrer *this, UFG::qVector3 *currPosition)
{
  return this->mTimeTolerance < this->mTimeSinceLastCheck
      || (float)((float)((float)((float)(this->mLastPosition.y - currPosition->y)
                               * (float)(this->mLastPosition.y - currPosition->y))
                       + (float)((float)(this->mLastPosition.x - currPosition->x)
                               * (float)(this->mLastPosition.x - currPosition->x)))
               + (float)((float)(this->mLastPosition.z - currPosition->z)
                       * (float)(this->mLastPosition.z - currPosition->z))) > (float)(this->mDistanceTolerance
                                                                                    * this->mDistanceTolerance);
}

