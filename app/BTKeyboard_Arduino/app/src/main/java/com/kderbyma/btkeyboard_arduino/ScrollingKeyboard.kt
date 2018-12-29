package com.kderbyma.btkeyboard_arduino

import android.content.Context
import android.os.Bundle
import android.support.design.widget.Snackbar
import android.support.v7.app.AppCompatActivity
import android.view.Menu
import android.view.MenuItem
import kotlinx.android.synthetic.main.activity_scrolling_keyboard.*
import android.opengl.ETC1.getWidth
import android.graphics.BitmapFactory
import android.graphics.Bitmap
import android.graphics.Canvas
import android.graphics.Paint
import android.view.View


class ScrollingKeyboard : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_scrolling_keyboard)
        setSupportActionBar(toolbar)
        fab.setOnClickListener { view ->
            Snackbar.make(view, "Replace with your own action", Snackbar.LENGTH_LONG)
                .setAction("Action", null).show()
        }
    }

    override fun onCreateOptionsMenu(menu: Menu): Boolean {
        // Inflate the menu; this adds items to the action bar if it is present.
        menuInflater.inflate(R.menu.menu_scrolling_keyboard, menu)
        return true
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.

        return when (item.itemId) {
            R.id.action_settings -> true
            else -> super.onOptionsItemSelected(item)
        }
    }
}

internal class Piano(context: Context)// TODO Auto-generated constructor stub
    : View(context) {

    var whiteKey: Bitmap? = null
    var blackKey: Bitmap? = null
    var paint = Paint()

    override fun draw(canvas: Canvas) {
        super.draw(canvas)
        if (whiteKey == null) {
            whiteKey = BitmapFactory.decodeResource(getResources(), R.drawable.whiteKey)
        }
        if (blackKey == null) {
            blackKey = BitmapFactory.decodeResource(getResources(), R.drawable.blackKey)
        }

        val keys = 10

        // draw white keys
        for (i in 0 until keys) {
            canvas.drawBitmap(whiteKey, i * whiteKey!!.width, 0, paint)
        }
        // draw black keys
        for (i in 0 until keys) {
            if (i != 3 && i != 7) {
                canvas.drawBitmap(blackKey, i * blackKey!!.width + blackKey!!.width * 0.5f, 0, paint)
            }
        }
    }
};