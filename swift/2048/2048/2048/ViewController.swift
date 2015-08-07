//
//  ViewController.swift
//  2048
//
//  Created by wzcjj on 15/8/4.
//  Copyright (c) 2015年 wzcjj. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    @IBAction func startGame(sender:UIButton){
        let alertView = UIAlertView()
        alertView.title = "asd"
        alertView.message = "qwe"
        alertView.addButtonWithTitle("zxc")
        alertView.show()
    }
}

