#include <iostream>
#include <memory>
//Паттерн проектирования: фабричный метод
//Base class(fabric method)
//class Dialog
//void render()
//abstract Button createButton() - fabric method
//windowDialog: public Dialog
//Button creatButton() return Dialog
//class WebDialog : public Dialog
//Button creatButton() return htmlButton
class Button {
public:
	virtual void render() = 0;
	virtual ~Button() {}
};
class WindowsButton: public Button {
public:
	void render()override {
		std::cout << "Render Windows Button\n";
	}
};
class HTMLButton : public Button {
public:
	void render()override {
		std::cout << "Render HTML Button\n";
	}
};
class Dialog {
public:
	void render() {
		std::shared_ptr<Button> button = creatButton();
		button->render();
	}
	virtual std::shared_ptr<Button> creatButton() = 0;
	virtual ~Dialog() {}
};
class WindowsDialog :public Dialog {
public:
	std::shared_ptr<Button> creatButton()override {
		return std::make_shared<WindowsButton>();
	}
};
class WebDialog :public Dialog {
public:
	std::shared_ptr<Button> creatButton() override{
		return std::make_shared<HTMLButton>();
	}
};
int main() {
	setlocale(LC_ALL, "Russian");
	std::shared_ptr<Dialog> dialog;
	std::string config;
	std::cout << "Enter config : ";
	std::cin >> config;
	if (config == "Windows") {
		dialog = std::make_shared<WindowsDialog>();
	}
	else
		if (config == "Web") {
		dialog = std::make_shared<WebDialog>();
	}
	else {
		throw "Error:unknown config\n";
	}
	dialog->render();
	return 0;
}