#pragma once

#include "selfdrive/ui/qt/onroad/buttons.h"
#include "selfdrive/ui/qt/widgets/cameraview.h"

const int widget_size = img_size + (UI_BORDER_SIZE / 2);

class FrogPilotAnnotatedCameraWidget : public QWidget {
  Q_OBJECT

public:
  explicit FrogPilotAnnotatedCameraWidget(QWidget *parent = 0);

  void mousePressEvent(QMouseEvent *e) override;
  void paintFrogPilotWidgets(QPainter &p, UIState &s, FrogPilotUIState &fs, SubMaster &sm, SubMaster &fpsm);
  void updateState(const UIState &s, const FrogPilotUIState &fs);

  bool hideBottomIcons;
  bool isCruiseSet;
  bool rightHandDM;

  float speed;

  QJsonObject frogpilot_toggles;

  QPoint dmIconPosition;
  QPoint experimentalButtonPosition;

  QRect setSpeedRect;

  QSize defaultSize;

protected:
  void showEvent(QShowEvent *event) override;

private:
  void paintBlindSpotPath(QPainter &p, SubMaster &sm, SubMaster &fpsm);
  void paintCompass(QPainter &p);

  float distanceConversion;
  float setSpeed;
  float speedConversion;
  float speedConversionMetrics;

  Params params;
  Params params_memory{"", false, true};

  QColor blackColor(int alpha = 255) { return QColor(0, 0, 0, alpha); }
  QColor blueColor(int alpha = 255) { return QColor(0, 0, 255, alpha); }
  QColor redColor(int alpha = 255) { return QColor(201, 34, 49, alpha); }
  QColor whiteColor(int alpha = 255) { return QColor(255, 255, 255, alpha); }

  QPoint compassPosition;

  QString accelerationUnit;
  QString leadDistanceUnit;
  QString leadSpeedUnit;
  QString speedUnit;
};
