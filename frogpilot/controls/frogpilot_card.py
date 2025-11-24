#!/usr/bin/env python3
from cereal import car
from openpilot.common.params import Params

ButtonType = car.CarState.ButtonEvent.Type

class FrogPilotCard:
  def __init__(self, CP, FPCP):
    self.CP = CP

    self.params = Params()
    self.params_memory = Params(memory=True)

    self.accel_pressed = False
    self.decel_pressed = False

  def update(self, carState, frogpilotCarState, sm, frogpilot_toggles):
    if sm.updated["frogpilotPlan"] or any(be.type in (ButtonType.accelCruise, ButtonType.resumeCruise) for be in carState.buttonEvents):
      self.accel_pressed = any(be.type in (ButtonType.accelCruise, ButtonType.resumeCruise) for be in carState.buttonEvents)

    if sm.updated["frogpilotPlan"] or any(be.type == ButtonType.decelCruise for be in carState.buttonEvents):
      self.decel_pressed = any(be.type == ButtonType.decelCruise for be in carState.buttonEvents)

    frogpilotCarState.accelPressed = self.accel_pressed
    frogpilotCarState.decelPressed = self.decel_pressed

    return frogpilotCarState
