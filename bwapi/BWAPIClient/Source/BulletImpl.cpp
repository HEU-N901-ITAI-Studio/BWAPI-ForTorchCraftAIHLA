#include <BWAPI.h>
#include "GameImpl.h"
#include "ForceImpl.h"
#include "PlayerImpl.h"
#include "UnitImpl.h"
#include "BulletImpl.h"

#include <Util\Foreach.h>

#include <string>
namespace BWAPI
{
  BulletImpl::BulletImpl(int index)
  {
    this->self=&(BWAPI::BWAPIClient.data->bullets[index]);
    this->index=index;
  }
  int BulletImpl::getID() const
  {
    return self->id;
  }
  Player* BulletImpl::getPlayer() const
  {
    return ((GameImpl*)Broodwar)->getPlayer(self->player);
  }
  BulletType BulletImpl::getType() const
  {
    return BulletType(self->type);
  }
  Unit* BulletImpl::getSource() const
  {
    return ((GameImpl*)Broodwar)->getUnit(self->source);
  }
  Position BulletImpl::getPosition() const
  {
    return Position(self->positionX,self->positionY);
  }
  double BulletImpl::getAngle() const
  {
    return self->angle;
  }
  double BulletImpl::getVelocityX() const
  {
    return self->velocityX;
  }
  double BulletImpl::getVelocityY() const
  {
    return self->velocityY;
  }
  Unit* BulletImpl::getTarget() const
  {
    return ((GameImpl*)Broodwar)->getUnit(self->target);
  }
  Position BulletImpl::getTargetPosition() const
  {
    return Position(self->targetPositionX,self->targetPositionY);
  }
  int BulletImpl::getRemoveTimer() const
  {
    return self->removeTimer;
  }
  bool BulletImpl::exists() const
  {
    return self->exists;
  }
  bool BulletImpl::isVisible() const
  {
    return self->isVisible[self->player];
  }
  bool BulletImpl::isVisible(Player* player) const
  {
    return self->isVisible[player->getID()];
  }
}