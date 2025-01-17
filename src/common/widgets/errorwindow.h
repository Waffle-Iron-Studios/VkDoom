#pragma once

#include <zwidget/core/widget.h>
#include <zwidget/core/span_layout.h>

class LogViewer;
class PushButton;

class ErrorWindow : public Widget
{
public:
	static bool ExecModal(const std::string& text, const std::string& log);

	ErrorWindow();

	bool Restart = false;

protected:
	void OnClose() override;
	void OnGeometryChanged() override;

private:
	void SetText(const std::string& text, const std::string& log);

	void OnClipboardButtonClicked();
	void OnRestartButtonClicked();

	LogViewer* LogView = nullptr;
	PushButton* ClipboardButton = nullptr;
	PushButton* RestartButton = nullptr;

	std::string clipboardtext;
};

class LogViewer : public Widget
{
public:
	LogViewer(Widget* parent);

	void SetText(const std::string& text, const std::string& log);

protected:
	void OnPaintFrame(Canvas* canvas) override;
	void OnPaint(Canvas* canvas) override;

private:
	SpanLayout CreateLineLayout(const std::string& text);

	std::shared_ptr<Font> largefont = Font::Create("Poppins", 16.0);
	std::shared_ptr<Font> font = Font::Create("Poppins", 12.0);
	std::vector<SpanLayout> lines;
};
